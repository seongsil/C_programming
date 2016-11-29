/*********************************
*                                *
* 학번 : 20133277                *
* 이름 : 허성실                  *
*                                *
**********************************/

#include<iostream>         // 표준입출력사용
#include<fstream>         // 파일 입력사용
#include <windows.h>     // Sleep 사용
#include <ctime>
#include <curses.h>       // pdcurses 모드사용
#include "MainWin.h"      // 메인 화면
#include "ScoreWin.h"      // 점수 화면
#include "NameWin.h"       // 이름 화면
#include "Tetromino.h"        // 테트로미노  

using namespace std;


int main()
{	
	//srand((unsigned)time(0));
	ifstream inStream;

	MainWin Main;          // 메인화면 생성
	Tetromino Tetro(&Main);  // Tetromino와 Mainwin 연결
	
	cout << "테트리스 게임을 시작합니다." << endl;
	cout << "사용자의 이름을 입력하세요." << endl;
	cout << " 이름 : ";
	char NAME[10];
	cin >> NAME ;

	NameWin Name(NAME);

	//파일입력을 사용하려면 1번 아니면 0번
	cout<<"파일입력 사용은 1번, 키보드입력 사용은 0을 눌러주세요"<<endl;

	int g;
	cin>>g;
	if(g)
	inStream.open("input.txt");
	
	// 테트리스 시작!!!
	initscr(); //기본 크기 윈도우 생성

	keypad(stdscr,TRUE); //키보드 입력설정
	noecho(); //입력한 키 값을 화면에 보이지 않게 하기
	curs_set(0);//커서 없애기

	resize_term(25,50); //터미널 크기 설정
	start_color(); //색 시작하겠다.
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	init_pair(1,COLOR_BLUE,COLOR_BLACK);    // 폰트 녹색, 폰트배경 검은색
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	     // 폰트 빨강색,폰트배경 검은색
	init_pair(3,COLOR_MAGENTA,COLOR_BLACK);    // 폰트 흰색,폰트배경 검은색
	init_pair(4,COLOR_RED,COLOR_BLACK);
	init_pair(5,COLOR_CYAN,COLOR_BLACK);
	init_pair(6,COLOR_WHITE,COLOR_BLACK);
	init_pair(8,COLOR_BLACK,COLOR_BLACK);

	border('|','|','-','-','+','+','+','+');  //창 테두리 설정
	refresh();  //화면 실제출력

	// 처음 떨어지는 좌표설정
	int row=1;
	int col=9;

	// 처음에 떨어지는 도형의 모양,회전 설정
	int shape=0;
	int rotate=0;

	// 게임 종료 설정
	int isGameOver=1;
	int seed;
	inStream >> seed;

	while(1)
	{
		Main.PrintWin(); //테트리스 창 출력
		
		//입력파일이 있으면 파일 내용에 따라 블록 위치 조정,
		//없으면 키보드 입력에 따라 블록위치 조정
		if(!inStream.fail())
		{
			char key;
			inStream >> key;

			Tetro.Move(shape,rotate,key,row,col); // r은 테트로미노 s는 스핀 key는 방향 a,b는 좌표로 테트로미노를 움직인다.

			if(key=='q') // 'q' 입력시 게임종료 
			{	
			Tetro.Print(shape,rotate,row,col,Main.GetWin());   // 테트로미노 출력
			wrefresh(Main.GetWin());            // 메인보드 출력
			isGameOver=0; //종료설정
			break;
			}

			if(Tetro.Input(shape,rotate,row,col)==1)
			{                                        // 반환값이 1이면 저장후에 새로운 블럭좌표 설정
				shape=rand()%seed; 
				row=1;
				col=9;
			}
		}
		else
		{
				switch(getch())//입력값 확인
				{  
				case KEY_LEFT: //방향키 왼쪽
					Tetro.Move(shape,rotate,'l',row,col);
					break;
				case KEY_RIGHT: //방향키 오른쪽
					Tetro.Move(shape,rotate,'r',row,col);
					break;
				case KEY_DOWN: // 방향키 아래
					Tetro.Move(shape,rotate,'g',row,col);
					break;
				case ' ': // spacebar 입력 시
					Tetro.Move(shape,rotate,'d',row,col);
					break;
				case KEY_UP:
					Tetro.Move(shape,rotate,'t',row,col);
					break;
				case 'q' : // 'q' 입력시 게임종료
					isGameOver=0;
					break;
				}

			// 네모 0, 회전횟수 0, row좌표 ,col좌표 입력
			if(Tetro.Print(shape,rotate,row,col,Main.GetWin())==1)
			{       // 반환값이 1이면 저장후에 새로운 좌표 입력
				shape=rand()%7;
				row=1;
				col=9;
				rotate=0;
				Tetro.Print(shape,rotate,row,col,Main.GetWin());
			}
			wrefresh(Main.GetWin());            // 메인보드 출력
		}

		Main.DeleteBoard();  // 한 줄 다 채워지면 점수 증가 및 한줄 제거

		ScoreWin Score(Main.GetScore()); //메인의 점수 불러오기
		Score.PrintWin();// 그래서 점수 출력!
		Name.PrintWin();

		for(int i=1; i<=10; i++) //맨 윗줄에 블럭 하나라도 차있을 경우 게임 종료    
		{
				if(Main.BlockExist(1,i)==1)
				isGameOver = 0;
		}

		if(isGameOver==0)    //게임설정이 0이면 게임종료
			break;

	}

	mvprintw(22,10,"점수는 %d입니다.",Main.GetScore());
	mvprintw(23,10,"게임을 종료하려면 아무키나 눌러주세요"); 
	refresh();
	getch();
	endwin();

	return 0;
}


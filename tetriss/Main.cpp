/*********************************
*                                *
* �й� : 20133277                *
* �̸� : �㼺��                  *
*                                *
**********************************/

#include<iostream>         // ǥ������»��
#include<fstream>         // ���� �Է»��
#include <windows.h>     // Sleep ���
#include <ctime>
#include <curses.h>       // pdcurses �����
#include "MainWin.h"      // ���� ȭ��
#include "ScoreWin.h"      // ���� ȭ��
#include "NameWin.h"       // �̸� ȭ��
#include "Tetromino.h"        // ��Ʈ�ι̳�  

using namespace std;


int main()
{	
	//srand((unsigned)time(0));
	ifstream inStream;

	MainWin Main;          // ����ȭ�� ����
	Tetromino Tetro(&Main);  // Tetromino�� Mainwin ����
	
	cout << "��Ʈ���� ������ �����մϴ�." << endl;
	cout << "������� �̸��� �Է��ϼ���." << endl;
	cout << " �̸� : ";
	char NAME[10];
	cin >> NAME ;

	NameWin Name(NAME);

	//�����Է��� ����Ϸ��� 1�� �ƴϸ� 0��
	cout<<"�����Է� ����� 1��, Ű�����Է� ����� 0�� �����ּ���"<<endl;

	int g;
	cin>>g;
	if(g)
	inStream.open("input.txt");
	
	// ��Ʈ���� ����!!!
	initscr(); //�⺻ ũ�� ������ ����

	keypad(stdscr,TRUE); //Ű���� �Է¼���
	noecho(); //�Է��� Ű ���� ȭ�鿡 ������ �ʰ� �ϱ�
	curs_set(0);//Ŀ�� ���ֱ�

	resize_term(25,50); //�͹̳� ũ�� ����
	start_color(); //�� �����ϰڴ�.
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	init_pair(1,COLOR_BLUE,COLOR_BLACK);    // ��Ʈ ���, ��Ʈ��� ������
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	     // ��Ʈ ������,��Ʈ��� ������
	init_pair(3,COLOR_MAGENTA,COLOR_BLACK);    // ��Ʈ ���,��Ʈ��� ������
	init_pair(4,COLOR_RED,COLOR_BLACK);
	init_pair(5,COLOR_CYAN,COLOR_BLACK);
	init_pair(6,COLOR_WHITE,COLOR_BLACK);
	init_pair(8,COLOR_BLACK,COLOR_BLACK);

	border('|','|','-','-','+','+','+','+');  //â �׵θ� ����
	refresh();  //ȭ�� �������

	// ó�� �������� ��ǥ����
	int row=1;
	int col=9;

	// ó���� �������� ������ ���,ȸ�� ����
	int shape=0;
	int rotate=0;

	// ���� ���� ����
	int isGameOver=1;
	int seed;
	inStream >> seed;

	while(1)
	{
		Main.PrintWin(); //��Ʈ���� â ���
		
		//�Է������� ������ ���� ���뿡 ���� ��� ��ġ ����,
		//������ Ű���� �Է¿� ���� �����ġ ����
		if(!inStream.fail())
		{
			char key;
			inStream >> key;

			Tetro.Move(shape,rotate,key,row,col); // r�� ��Ʈ�ι̳� s�� ���� key�� ���� a,b�� ��ǥ�� ��Ʈ�ι̳븦 �����δ�.

			if(key=='q') // 'q' �Է½� �������� 
			{	
			Tetro.Print(shape,rotate,row,col,Main.GetWin());   // ��Ʈ�ι̳� ���
			wrefresh(Main.GetWin());            // ���κ��� ���
			isGameOver=0; //���ἳ��
			break;
			}

			if(Tetro.Input(shape,rotate,row,col)==1)
			{                                        // ��ȯ���� 1�̸� �����Ŀ� ���ο� ����ǥ ����
				shape=rand()%seed; 
				row=1;
				col=9;
			}
		}
		else
		{
				switch(getch())//�Է°� Ȯ��
				{  
				case KEY_LEFT: //����Ű ����
					Tetro.Move(shape,rotate,'l',row,col);
					break;
				case KEY_RIGHT: //����Ű ������
					Tetro.Move(shape,rotate,'r',row,col);
					break;
				case KEY_DOWN: // ����Ű �Ʒ�
					Tetro.Move(shape,rotate,'g',row,col);
					break;
				case ' ': // spacebar �Է� ��
					Tetro.Move(shape,rotate,'d',row,col);
					break;
				case KEY_UP:
					Tetro.Move(shape,rotate,'t',row,col);
					break;
				case 'q' : // 'q' �Է½� ��������
					isGameOver=0;
					break;
				}

			// �׸� 0, ȸ��Ƚ�� 0, row��ǥ ,col��ǥ �Է�
			if(Tetro.Print(shape,rotate,row,col,Main.GetWin())==1)
			{       // ��ȯ���� 1�̸� �����Ŀ� ���ο� ��ǥ �Է�
				shape=rand()%7;
				row=1;
				col=9;
				rotate=0;
				Tetro.Print(shape,rotate,row,col,Main.GetWin());
			}
			wrefresh(Main.GetWin());            // ���κ��� ���
		}

		Main.DeleteBoard();  // �� �� �� ä������ ���� ���� �� ���� ����

		ScoreWin Score(Main.GetScore()); //������ ���� �ҷ�����
		Score.PrintWin();// �׷��� ���� ���!
		Name.PrintWin();

		for(int i=1; i<=10; i++) //�� ���ٿ� �� �ϳ��� ������ ��� ���� ����    
		{
				if(Main.BlockExist(1,i)==1)
				isGameOver = 0;
		}

		if(isGameOver==0)    //���Ӽ����� 0�̸� ��������
			break;

	}

	mvprintw(22,10,"������ %d�Դϴ�.",Main.GetScore());
	mvprintw(23,10,"������ �����Ϸ��� �ƹ�Ű�� �����ּ���"); 
	refresh();
	getch();
	endwin();

	return 0;
}


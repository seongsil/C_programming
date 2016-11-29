#ifndef MainWin_H
#define MainWin_H


#include <curses.h>

class MainWin   //메인보드 (첫번째 창)
{    
   	int score; 
	int board[50][50]; //네모의 위치를 2차원배열로 표현
	int nowboard[50][50];
	WINDOW *win1;

public:
	MainWin();//생성자 함수
	void PrintWin();
	WINDOW* GetWin() {return win1;} 
	void SaveBoard(int a,int b,int n){ board[a][b]=n; } //a,b에 n값을 0또는 1(블럭있다)로 저장
	void NowBoard(int a, int b, int n){ nowboard[a][b]=n;} //현재 블럭이 0 또는 1(블럭있다) 판단
	int NowExist(int a, int b) { return nowboard[a][b];}
	int BlockExist(int a,int b){return board[a][b];}  // 블럭있는지 없는지 반환 
    void DeleteBoard();    // 한줄 다 채워졌을 경우 제거 
	int GetScore(){ return score; } // 점수 반환
	
};




#endif
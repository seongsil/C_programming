#ifndef MainWin_H
#define MainWin_H


#include <curses.h>

class MainWin   //���κ��� (ù��° â)
{    
   	int score; 
	int board[50][50]; //�׸��� ��ġ�� 2�����迭�� ǥ��
	int nowboard[50][50];
	WINDOW *win1;

public:
	MainWin();//������ �Լ�
	void PrintWin();
	WINDOW* GetWin() {return win1;} 
	void SaveBoard(int a,int b,int n){ board[a][b]=n; } //a,b�� n���� 0�Ǵ� 1(���ִ�)�� ����
	void NowBoard(int a, int b, int n){ nowboard[a][b]=n;} //���� ���� 0 �Ǵ� 1(���ִ�) �Ǵ�
	int NowExist(int a, int b) { return nowboard[a][b];}
	int BlockExist(int a,int b){return board[a][b];}  // ���ִ��� ������ ��ȯ 
    void DeleteBoard();    // ���� �� ä������ ��� ���� 
	int GetScore(){ return score; } // ���� ��ȯ
	
};




#endif
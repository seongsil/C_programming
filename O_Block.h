#ifndef OBLOCK_H
#define OBLOCK_H

#include <curses.h>
#include "MainWin.h"

class O_Block : public MainWin
{
private:
	MainWin *board;      // ���κ��� ��ü ����
	MainWin Main;
public:
	void SetBoard(MainWin* main){  board=main; }  // ������� ��ü board�� ��Ʈ���� ���κ���� �����Ѵ�(���� ���� , ���κ��带 ���������ϵ���)
	virtual void Move(char d,int& row,int& col); // inputfile�� Ű ( ���������� ������ ������ �����Լ����� ������ �����ϵ���)
    virtual int SavePrint(int row,int col,WINDOW *win1);     //Ű���� �Է� ��� ���,����
	int Save(int row,int col);       // Inputfile ��� ����
 	
};


#endif
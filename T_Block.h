#ifndef TBLOCK_H
#define TBLOCK_H

#include <curses.h>
#include "MainWin.h"

class T_Block : public MainWin
{
private:
	MainWin *board;      // ���κ��� ��ü ����
public:
	void SetBoard(MainWin* main){  board=main; }  // ������� ��ü board�� ��Ʈ���� ���κ���� �����Ѵ�(���� ���� , ���κ��带 ���������ϵ���)
	virtual void Move(int &rotate,char d,int& row,int& col); // inputfile�� Ű ( ���������� ������ ������ �����Լ����� ������ �����ϵ���)
    virtual int SavePrint(int rotate,int row,int col,WINDOW *win1);     //Ű���� �Է� ��� ���,����
	int Save(int rotate,int row,int col);       // Inputfile ��� ����
 	
};


#endif
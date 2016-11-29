#ifndef OBLOCK_H
#define OBLOCK_H

#include <curses.h>
#include "MainWin.h"

class O_Block : public MainWin
{
private:
	MainWin *board;      // 메인보드 객체 생성
	MainWin Main;
public:
	void SetBoard(MainWin* main){  board=main; }  // 멤버변수 객체 board를 테트리스 메인보드로 복사한다(얕은 복사 , 메인보드를 수정가능하도록)
	virtual void Move(char d,int& row,int& col); // inputfile값 키 ( 참조변수로 선언한 이유는 메인함수에서 변수값 수정하도록)
    virtual int SavePrint(int row,int col,WINDOW *win1);     //키보드 입력 방식 출력,저장
	int Save(int row,int col);       // Inputfile 방식 저장
 	
};


#endif
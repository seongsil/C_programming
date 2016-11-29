#ifndef TETROMINO_H
#define TETROMINO_H

#include "O_Block.h"
#include "I_Block.h"
#include "L_Block.h"
#include "J_Block.h"
#include "S_Block.h"
#include "Z_Block.h"
#include "T_Block.h"

class Tetromino
{  
private:
	O_Block *OBlock;        //0번 네모 객체 생성
	I_Block *IBlock;       //6번 막대기 객체 생성
	L_Block *LBlock;
	J_Block *JBlock;
	S_Block *SBlock;
	Z_Block *ZBlock;
	T_Block *TBlock;

public:
	Tetromino(MainWin* main)
	      {  
			 OBlock=new O_Block;        // O_Block 메모리 할당
	         OBlock->SetBoard(main);// 수정 가능하도록 O_Block 안 맴버변수로 있는 메인보드를 원래 메인보드(main)로 얕은 복사

			 LBlock = new L_Block;
			 LBlock->SetBoard(main);

			 JBlock = new J_Block;
			 JBlock->SetBoard(main);

			 SBlock = new S_Block;
			 SBlock->SetBoard(main);

			 IBlock = new I_Block;
			 IBlock->SetBoard(main);

			 ZBlock = new Z_Block;
			 ZBlock->SetBoard(main);

			 TBlock = new T_Block;
			 TBlock->SetBoard(main);
	      }
	virtual void Move(int shape,int &rotate,char d,int& row,int& col);  
	int Print(int shape,int rotate, int row, int col,WINDOW *win1); // 키보드 입력방식
	int Input(int shape,int rotate, int row, int col); // input파일 입력방식
};

#endif
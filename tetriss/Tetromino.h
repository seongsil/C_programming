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
	O_Block *OBlock;        //0�� �׸� ��ü ����
	I_Block *IBlock;       //6�� ����� ��ü ����
	L_Block *LBlock;
	J_Block *JBlock;
	S_Block *SBlock;
	Z_Block *ZBlock;
	T_Block *TBlock;

public:
	Tetromino(MainWin* main)
	      {  
			 OBlock=new O_Block;        // O_Block �޸� �Ҵ�
	         OBlock->SetBoard(main);// ���� �����ϵ��� O_Block �� �ɹ������� �ִ� ���κ��带 ���� ���κ���(main)�� ���� ����

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
	int Print(int shape,int rotate, int row, int col,WINDOW *win1); // Ű���� �Է¹��
	int Input(int shape,int rotate, int row, int col); // input���� �Է¹��
};

#endif
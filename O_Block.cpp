#include "O_Block.h"
#include "MainWin.h"

void O_Block::Move(char d,int& row,int& col)
{
	switch(d) //각각 키들의 기능 구현
	{  
	case 'l':     //왼쪽으로 한칸(벽일때, 왼쪽에 블럭있을때, 이동불가)
		if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1 )       
		{ col-=2;}
		break;
	case 'r': //오른쪽으로 한칸(벽일때, 오른쪽에 블럭있을때, 이동불가)
		if(col!=17 && board->BlockExist(row,(col+5)/2)!=1 && board->BlockExist(row+1,(col+5)/2)!=1)
		{col+=2;}
		break;
	case 'g': // 아래로 한칸(바닥일때, 아래에 블럭있을 경우 이동불가)
		if(row!=17 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 )
		{
			row++;
		}
		break;
	case 'd': // spacebar 입력시,바닥일때, 아래에 블럭있을 경우까지 반복
		while(row!=17 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1)
		{
			row++;
		}
		break;
	}

}
int O_Block::SavePrint(int row,int col,WINDOW *win1)
{
	wattron(win1,COLOR_PAIR(7));

	// 블럭이 바닥에 있거나 아래에 있을 경우
	mvwprintw(board->GetWin(),row,col,"■■");
	mvwprintw(board->GetWin(),row+1,col,"■■");

	if(row==17 || board->BlockExist(row+2,(col+1)/2)==1 || board->BlockExist(row+2,(col+3)/2)==1 )
	{
		board->SaveBoard(row,(col+1)/2,1);
		board->SaveBoard(row,(col+3)/2,1);
		board->SaveBoard(row+1,(col+1)/2,1);
		board->SaveBoard(row+1,(col+3)/2,1);

		return 1;
	}

	else
	{
		return 0;
	}

	wattroff(win1,COLOR_PAIR(7));
}

int O_Block::Save(int row,int col)
{
	// 블럭이 바닥에 있거나 아래에 있을 경우
	if(row==17 || board->BlockExist(row+2,(col+1)/2)==1 || board->BlockExist(row+2,(col+3)/2)==1 )
	{
		board->SaveBoard(row,(col+1)/2,1);
		board->SaveBoard(row,(col+3)/2,1);
		board->SaveBoard(row+1,(col+1)/2,1);
		board->SaveBoard(row+1,(col+3)/2,1);

		return 1;
	}
	else
	{	
		return 0;
	}

}
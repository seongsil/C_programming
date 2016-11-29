#include "S_Block.h"

void S_Block::Move(int &rotate, char d,int& row,int& col)
{
	if(rotate%2==0) //기본형태
	{
		switch(d) //각각 키들의 기능 구현
		{  
		case 'l':     //왼쪽으로 한칸(벽일때, 왼쪽에 블럭있을때, 이동불가)
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1 && board->BlockExist(row+2,(col+1)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //오른쪽으로 한칸(벽일때, 오른쪽에 블럭있을때, 이동불가)
			if(col!=17 && board->BlockExist(row,(col+3)/2)!=1 && board->BlockExist(row+1,(col+5)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
			{col+=2;}
			break;
		case 'g': // 아래로 한칸(바닥일때, 아래에 블럭있을 경우 이동불가)
			if(row!=16 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+3,(col+3)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar 입력시,바닥일때, 아래에 블럭있을 경우까지 반복
			while(row!=16 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+3,(col+3)/2)!=1)
			{
				row++;
			}
			break;
		case 't':
			if(col!=1 && board->BlockExist(row+1,(col-1)/2)!=1 && board->BlockExist(row,(col+3)/2)!=1)
			{
				rotate++;
			}
		}
	}
	else if(rotate%2==1) //1회회전
	{
		switch(d) //각각 키들의 기능 구현
		{  
		case 'l':     //왼쪽으로 한칸(벽일때, 왼쪽에 블럭있을때, 이동불가)
			if(col!=3 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-3)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //오른쪽으로 한칸(벽일때, 오른쪽에 블럭있을때, 이동불가)
			if(col!=17 && board->BlockExist(row,(col+5)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
			{col+=2;}
			break;
		case 'g': // 아래로 한칸(바닥일때, 아래에 블럭있을 경우 이동불가)
			if(row!=17 && board->BlockExist(row+2,(col-1)/2)!=1 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar 입력시,바닥일때, 아래에 블럭있을 경우까지 반복
			while(row!=17 && board->BlockExist(row+2,(col-1)/2)!=1 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
			{
				row++;
			}
			break;
		case 't':
			if(row!=17 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1)
			{
				rotate++;
			}
		}
	}
}

int S_Block::SavePrint(int rotate,int row,int col,WINDOW *win1)
{
	wattron(win1,COLOR_PAIR(3));
	if(rotate%2==0) //기본 형태
	{
		mvwprintw(board->GetWin(),row,col,"■");
		mvwprintw(board->GetWin(),row+1,col,"■■");
		mvwprintw(board->GetWin(),row+2,col+2,"■");

		if(row!=16 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+3,(col+3)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+1,(col+3)/2,1);
			board->SaveBoard(row+2,(col+3)/2,1);

			return 1;

		}
	}

	else if(rotate%2==1) //1회 회전
	{
			mvwprintw(board->GetWin(),row,col,"■■");
			mvwprintw(board->GetWin(),row+1,col-2,"■■");

		if(row!=17 && board->BlockExist(row+2,(col-1)/2)!=1 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row,(col+3)/2,1);
			board->SaveBoard(row+1,(col-1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);

			return 1;

		}
	}
	wattroff(win1,COLOR_PAIR(3));
}

int S_Block::Save(int rotate,int row,int col)
{
	if(rotate%2==0) //기본 형태
	{
		if(row!=16 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+3,(col+3)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+1,(col+3)/2,1);
			board->SaveBoard(row+2,(col+3)/2,1);

			return 1;

		}
	}

	else if(rotate%2==1) //1회 회전
	{
		if(row!=17 && board->BlockExist(row+2,(col-1)/2)!=1 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row,(col+3)/2,1);
			board->SaveBoard(row+1,(col-1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);

			return 1;

		}
	}
}
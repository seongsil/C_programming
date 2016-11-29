#include "I_Block.h"

void I_Block::Move(int &rotate, char d,int& row,int& col)
{
	if(rotate%2==0)
	{
		switch(d) //각각 키들의 기능 구현
		{  
		case 'l':     //왼쪽으로 한칸(벽일때, 왼쪽에 블럭있을때, 이동불가)
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1 && board->BlockExist(row+2,(col-1)/2)!=1 && board->BlockExist(row+3,(col-1)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //오른쪽으로 한칸(벽일때, 오른쪽에 블럭있을때, 이동불가)
			if(col!=19 && board->BlockExist(row,(col+3)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 && board->BlockExist(row+3,(col+3)/2)!=1)
			{col+=2;}
			break;
		case 'g': // 아래로 한칸(바닥일때, 아래에 블럭있을 경우 이동불가)
			if(row!=15 && board->BlockExist(row+4,(col+1)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar 입력시,바닥일때, 아래에 블럭있을 경우까지 반복
			while(row!=15 && board->BlockExist(row+4,(col+1)/2)!=1)
			{
				row++;
			}
			break;
		case 't':
			if(col!=1 && col!=17 && col!=19 && board->BlockExist(row+1,(col+1)/2)!=1 &&  board->BlockExist(row+1,(col+3)/2)!=1 &&  board->BlockExist(row+1,(col+5)/2)!=1)
			{
				rotate++;
			}
		}
	}
	else
	{
		switch(d) //각각 키들의 기능 구현
		{  
		case 'l':     //왼쪽으로 한칸(벽일때, 왼쪽에 블럭있을때, 이동불가)
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //오른쪽으로 한칸(벽일때, 오른쪽에 블럭있을때, 이동불가)
			if(col!=13 && board->BlockExist(row,(col+9)/2)!=1)
			{col+=2;}
			break;
		case 'g': // 아래로 한칸(바닥일때, 아래에 블럭있을 경우 이동불가)
			if(row!=18 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+1,(col+5)/2)!=1 && board->BlockExist(row+1,(col+7)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar 입력시,바닥일때, 아래에 블럭있을 경우까지 반복
			while(row!=18 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+1,(col+5)/2)!=1 && board->BlockExist(row+1,(col+7)/2)!=1)
			{
				row++;
			}
			break;
		case 't':
			if(row!=1 && row!=14 && row!=15 && board->BlockExist(row-1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+2,(col+1)/2)!=1)
			{
				rotate++;
			}
		}
	}

}

int I_Block::SavePrint(int rotate,int row,int col,WINDOW *win1)
{
	wattron(win1,COLOR_PAIR(0));
	if(rotate%2==0) //회전안했을 때나 짝수번 회전
	{
		if(row!=15 && board->BlockExist(row+4,(col+1)/2)!=1)
		{
			mvwprintw(board->GetWin(),row,col,"■");
			mvwprintw(board->GetWin(),row+1,col,"■");
			mvwprintw(board->GetWin(),row+2,col,"■");
			mvwprintw(board->GetWin(),row+3,col,"■");

			return 0;
		}

		else
		{
			mvwprintw(board->GetWin(),row,col,"■");
			mvwprintw(board->GetWin(),row+1,col,"■");
			mvwprintw(board->GetWin(),row+2,col,"■");
			mvwprintw(board->GetWin(),row+3,col,"■");

			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+2,(col+1)/2,1);
			board->SaveBoard(row+3,(col+1)/2,1);


			return 1;

		}
	}
	else //홀수번 회전
	{
		if(row!=18 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+1,(col+5)/2)!=1 && board->BlockExist(row+1,(col+7)/2)!=1)
		{
			mvwprintw(board->GetWin(),row,col,"■■■■");

			return 0;
		}
		else
		{
			mvwprintw(board->GetWin(),row,col,"■■■■");

			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row,(col+3)/2,1);
			board->SaveBoard(row,(col+5)/2,1);
			board->SaveBoard(row,(col+7)/2,1);

			return 1;
		}
	}
	wattroff(win1,COLOR_PAIR(0));
}

	int I_Block::Save(int rotate,int row,int col)
	{
		if(rotate%2==0) //회전안했을 때나 짝수번 회전
		{
			if(row==15 || board->BlockExist(row+4,(col+1)/2)==1)
			{
				board->SaveBoard(row,(col+1)/2,1);
				board->SaveBoard(row+1,(col+1)/2,1);
				board->SaveBoard(row+2,(col+1)/2,1);
				board->SaveBoard(row+3,(col+1)/2,1);

				return 1;
			}

			else
			{
				return 0;
			}
		}
		else
		{
			if(row==15 || board->BlockExist(row+4,(col+1)/2)==1  )
			{
				board->SaveBoard(row,(col+1)/2,1);
				board->SaveBoard(row,(col+3)/2,1);
				board->SaveBoard(row,(col+5)/2,1);
				board->SaveBoard(row,(col+7)/2,1);

				return 1;
			}

			else
			{
				return 0;
			}
		}

	}

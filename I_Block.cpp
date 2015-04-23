#include "I_Block.h"

void I_Block::Move(int &rotate, char d,int& row,int& col)
{
	if(rotate%2==0)
	{
		switch(d) //���� Ű���� ��� ����
		{  
		case 'l':     //�������� ��ĭ(���϶�, ���ʿ� ��������, �̵��Ұ�)
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1 && board->BlockExist(row+2,(col-1)/2)!=1 && board->BlockExist(row+3,(col-1)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //���������� ��ĭ(���϶�, �����ʿ� ��������, �̵��Ұ�)
			if(col!=19 && board->BlockExist(row,(col+3)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 && board->BlockExist(row+3,(col+3)/2)!=1)
			{col+=2;}
			break;
		case 'g': // �Ʒ��� ��ĭ(�ٴ��϶�, �Ʒ��� ������ ��� �̵��Ұ�)
			if(row!=15 && board->BlockExist(row+4,(col+1)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar �Է½�,�ٴ��϶�, �Ʒ��� ������ ������ �ݺ�
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
		switch(d) //���� Ű���� ��� ����
		{  
		case 'l':     //�������� ��ĭ(���϶�, ���ʿ� ��������, �̵��Ұ�)
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //���������� ��ĭ(���϶�, �����ʿ� ��������, �̵��Ұ�)
			if(col!=13 && board->BlockExist(row,(col+9)/2)!=1)
			{col+=2;}
			break;
		case 'g': // �Ʒ��� ��ĭ(�ٴ��϶�, �Ʒ��� ������ ��� �̵��Ұ�)
			if(row!=18 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+1,(col+5)/2)!=1 && board->BlockExist(row+1,(col+7)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar �Է½�,�ٴ��϶�, �Ʒ��� ������ ������ �ݺ�
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
	if(rotate%2==0) //ȸ�������� ���� ¦���� ȸ��
	{
		if(row!=15 && board->BlockExist(row+4,(col+1)/2)!=1)
		{
			mvwprintw(board->GetWin(),row,col,"��");
			mvwprintw(board->GetWin(),row+1,col,"��");
			mvwprintw(board->GetWin(),row+2,col,"��");
			mvwprintw(board->GetWin(),row+3,col,"��");

			return 0;
		}

		else
		{
			mvwprintw(board->GetWin(),row,col,"��");
			mvwprintw(board->GetWin(),row+1,col,"��");
			mvwprintw(board->GetWin(),row+2,col,"��");
			mvwprintw(board->GetWin(),row+3,col,"��");

			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+2,(col+1)/2,1);
			board->SaveBoard(row+3,(col+1)/2,1);


			return 1;

		}
	}
	else //Ȧ���� ȸ��
	{
		if(row!=18 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+1,(col+5)/2)!=1 && board->BlockExist(row+1,(col+7)/2)!=1)
		{
			mvwprintw(board->GetWin(),row,col,"�����");

			return 0;
		}
		else
		{
			mvwprintw(board->GetWin(),row,col,"�����");

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
		if(rotate%2==0) //ȸ�������� ���� ¦���� ȸ��
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

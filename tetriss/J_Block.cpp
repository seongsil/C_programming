#include "J_Block.h"

void J_Block::Move(int &rotate, char d,int& row,int& col)
{
	if(rotate%4==0) //�⺻����
	{
		switch(d) //���� Ű���� ��� ����
		{  
		case 'l':     //�������� ��ĭ(���϶�, ���ʿ� ��������, �̵��Ұ�)
			if(col!=3 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1 && board->BlockExist(row+2,(col-3)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //���������� ��ĭ(���϶�, �����ʿ� ��������, �̵��Ұ�)
			if(col!=19 && board->BlockExist(row,(col+3)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1)
			{col+=2;}
			break;
		case 'g': // �Ʒ��� ��ĭ(�ٴ��϶�, �Ʒ��� ������ ��� �̵��Ұ�)
			if(row!=16 && board->BlockExist(row+3,(col-1)/2)!=1 && board->BlockExist(row+3,(col+1)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar �Է½�,�ٴ��϶�, �Ʒ��� ������ ������ �ݺ�
			while(row!=16 && board->BlockExist(row+3,(col-1)/2)!=1 && board->BlockExist(row+3,(col+1)/2)!=1)
			{
				row++;
			}
			break;
		case 't':
			if(col!=19 && board->BlockExist(row+1,(col-1)/2)!=1 &&  board->BlockExist(row+1,(col+3)/2)!=1 &&  board->BlockExist(row+2,(col+3)/2)!=1)
			{
				rotate++;
			}
		}
	}
	else if(rotate%4==1) //1ȸȸ��
	{
		switch(d) //���� Ű���� ��� ����
		{  
		case 'l':     //�������� ��ĭ(���϶�, ���ʿ� ��������, �̵��Ұ�)
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //���������� ��ĭ(���϶�, �����ʿ� ��������, �̵��Ұ�)
			if(col!=15 && board->BlockExist(row,(col+7)/2)!=1 && board->BlockExist(row+1,(col+7)/2)!=1)
			{col+=2;}
			break;
		case 'g': // �Ʒ��� ��ĭ(�ٴ��϶�, �Ʒ��� ������ ��� �̵��Ұ�)
			if(row!=17 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar �Է½�,�ٴ��϶�, �Ʒ��� ������ ������ �ݺ�
			while(row!=17 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
			{
				row++;
			}
			break;
		case 't':
			if(row!=1 && board->BlockExist(row-1,(col+3)/2)!=1 && board->BlockExist(row-1,(col+5)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
			{
				rotate++;
			}
		}
	}
	else if(rotate%4==2) //2ȸ ȸ��
	{
		switch(d) //���� Ű���� ��� ����
		{  
		case 'l':     //�������� ��ĭ(���϶�, ���ʿ� ��������, �̵��Ұ�)
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1 && board->BlockExist(row+2,(col-1)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //���������� ��ĭ(���϶�, �����ʿ� ��������, �̵��Ұ�)
			if(col!=17 && board->BlockExist(row,(col+5)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1)
			{col+=2;}
			break;
		case 'g': // �Ʒ��� ��ĭ(�ٴ��϶�, �Ʒ��� ������ ��� �̵��Ұ�)
			if(row!=16 && board->BlockExist(row+3,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar �Է½�,�ٴ��϶�, �Ʒ��� ������ ������ �ݺ�
			while(row!=16 && board->BlockExist(row+3,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
			{
				row++;
			}
			break;
		case 't':
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
			{
				rotate++;
			}
		}
	}
	else if(rotate%4==3) //3ȸ ȸ��
	{
		switch(d) //���� Ű���� ��� ����
		{  
		case 'l':     //�������� ��ĭ(���϶�, ���ʿ� ��������, �̵��Ұ�)
			if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1)       
			{ col-=2;}
			break;
		case 'r': //���������� ��ĭ(���϶�, �����ʿ� ��������, �̵��Ұ�)
			if(col!=15 && board->BlockExist(row,(col+3)/2)!=1 && board->BlockExist(row+1,(col+7)/2)!=1)
			{col+=2;}
			break;
		case 'g': // �Ʒ��� ��ĭ(�ٴ��϶�, �Ʒ��� ������ ��� �̵��Ұ�)
			if(row!=17 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
			{
				row++;
			}
			break;
		case 'd': // spacebar �Է½�,�ٴ��϶�, �Ʒ��� ������ ������ �ݺ�
			while(row!=17 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
			{
				row++;
			}
			break;
		case 't':
			if(row!=17 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 && board->BlockExist(row,(col+3)/2)!=1)
			{
				rotate++;
			}
		}
	}

}

int J_Block::SavePrint(int rotate,int row,int col,WINDOW *win1)
{
	wattron(win1,COLOR_PAIR(2));
	if(rotate%4==0) //�⺻ ����
	{
		mvwprintw(board->GetWin(),row,col,"��");
		mvwprintw(board->GetWin(),row+1,col,"��");
		mvwprintw(board->GetWin(),row+2,col-2,"���");

		if(row!=16 && board->BlockExist(row+3,(col-1)/2)!=1 && board->BlockExist(row+3,(col+1)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+2,(col+1)/2,1);
			board->SaveBoard(row+2,(col-1)/2,1);

			return 1;

		}
	}

	else if(rotate%4==1) //1ȸ ȸ��
	{
		mvwprintw(board->GetWin(),row,col,"����");
		mvwprintw(board->GetWin(),row+1,col+4,"��");

		if(row!=17 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row,(col+3)/2,1);
			board->SaveBoard(row,(col+5)/2,1);
			board->SaveBoard(row+1,(col+5)/2,1);

			return 1;

		}
	}

	else if(rotate%4==2) //2ȸ ȸ��
	{
		mvwprintw(board->GetWin(),row,col,"���");
		mvwprintw(board->GetWin(),row+1,col,"��");
		mvwprintw(board->GetWin(),row+2,col,"��");

		if(row!=16 && board->BlockExist(row+3,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row,(col+3)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+2,(col+1)/2,1);

			return 1;

		}
	}

	else if(rotate%4==3) //3ȸ ȸ��
	{
		mvwprintw(board->GetWin(),row,col,"��");
		mvwprintw(board->GetWin(),row+1,col,"����");

		if(row!=17 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+1,(col+3)/2,1);
			board->SaveBoard(row+1,(col+5)/2,1);

			return 1;

		}
	}

	wattroff(win1,COLOR_PAIR(2));
}

int J_Block::Save(int rotate,int row,int col)
{
	if(rotate%4==0) //�⺻ ����
	{
		if(row!=16 && board->BlockExist(row+3,(col-1)/2)!=1 && board->BlockExist(row+3,(col+1)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+2,(col+1)/2,1);
			board->SaveBoard(row+2,(col-1)/2,1);

			return 1;

		}
	}

	else if(rotate%4==1) //1ȸ ȸ��
	{
		if(row!=17 && board->BlockExist(row+1,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row,(col+3)/2,1);
			board->SaveBoard(row,(col+5)/2,1);
			board->SaveBoard(row+1,(col+5)/2,1);

			return 1;

		}
	}

	else if(rotate%4==2) //2ȸ ȸ��
	{
		if(row!=16 && board->BlockExist(row+3,(col+1)/2)!=1 && board->BlockExist(row+1,(col+3)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row,(col+3)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+2,(col+1)/2,1);

			return 1;

		}
	}

	else if(rotate%4==3) //3ȸ ȸ��
	{
		if(row!=17 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 && board->BlockExist(row+2,(col+5)/2)!=1)
		{
			return 0;
		}

		else
		{
			board->SaveBoard(row,(col+1)/2,1);
			board->SaveBoard(row+1,(col+1)/2,1);
			board->SaveBoard(row+1,(col+3)/2,1);
			board->SaveBoard(row+1,(col+5)/2,1);

			return 1;
		}
	}
}
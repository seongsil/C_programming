#include "O_Block.h"
#include "MainWin.h"

void O_Block::Move(char d,int& row,int& col)
{
	switch(d) //���� Ű���� ��� ����
	{  
	case 'l':     //�������� ��ĭ(���϶�, ���ʿ� ��������, �̵��Ұ�)
		if(col!=1 && board->BlockExist(row,(col-1)/2)!=1 && board->BlockExist(row+1,(col-1)/2)!=1 )       
		{ col-=2;}
		break;
	case 'r': //���������� ��ĭ(���϶�, �����ʿ� ��������, �̵��Ұ�)
		if(col!=17 && board->BlockExist(row,(col+5)/2)!=1 && board->BlockExist(row+1,(col+5)/2)!=1)
		{col+=2;}
		break;
	case 'g': // �Ʒ��� ��ĭ(�ٴ��϶�, �Ʒ��� ������ ��� �̵��Ұ�)
		if(row!=17 && board->BlockExist(row+2,(col+1)/2)!=1 && board->BlockExist(row+2,(col+3)/2)!=1 )
		{
			row++;
		}
		break;
	case 'd': // spacebar �Է½�,�ٴ��϶�, �Ʒ��� ������ ������ �ݺ�
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

	// ���� �ٴڿ� �ְų� �Ʒ��� ���� ���
	mvwprintw(board->GetWin(),row,col,"���");
	mvwprintw(board->GetWin(),row+1,col,"���");

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
	// ���� �ٴڿ� �ְų� �Ʒ��� ���� ���
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
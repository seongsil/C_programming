#include "MainWin.h"


MainWin::MainWin()
{
	for(int i=1; i<19; i++)
		for(int j=1; j<11; j++)
		{
		  board[i][j]=0;
		  nowboard[i][j]=0;
		}

	score=0;
}

void MainWin::DeleteBoard()
{
	for(int a=1; a<19; a++) //���ٲ� á���� Ȯ��
	{
	    int cnt=0;	
		for(int b=1; b<11; b++)
		{
			if(board[a][b]==1)
			{
				cnt++;
			}
		}

		if(cnt==10) //������ ���� ��� ����̵� �ϰ� �����ø�
		{
			for(int i=a; i>1; i--) 
			 {  for(int j=1; j<11; j++)
			   {
				   board[i][j]=board[i-1][j];
			   }
			}
			   score++;
		}
	}
}

void MainWin::PrintWin()
{	
	// ù��° â
	win1=newwin(20,22,2,2);    
	wattron(win1,COLOR_PAIR(6)); 
	wborder(win1,'|','|','-','-','+','+','+','+');   

	                  
		for(int t=1; t<19; t++)
		{
			for(int k=0; k<10; k++)
				mvwprintw(win1,t*1,k*2+1,"��");
		}
		wattroff(win1,COLOR_PAIR(6)); 

		wattron(win1,COLOR_PAIR(2));
	for(int a=1; a<19; a++)
	{
		for(int b=1; b<11; b++)
		{
			if(board[a][b]==1)
			{
				mvwprintw(win1,a,2*b-1,"��");
			}
		}
	}
	wattroff(win1,COLOR_PAIR(2));
}	                                   
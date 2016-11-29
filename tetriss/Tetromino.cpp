#include"Tetromino.h"


void Tetromino :: Move(int shape,int &rotate, char d, int& row, int& col)
{
	if(shape==0) //네모
	{ 
		OBlock->Move(d,row,col);
	}

	else if(shape==1) //L
	{
		LBlock->Move(rotate,d,row,col);
	}

	else if(shape==2)
	{
		JBlock->Move(rotate,d,row,col);
	}

	else if(shape==3)
	{
		SBlock->Move(rotate,d,row,col);
	}

	else if(shape==4)
	{
		ZBlock->Move(rotate,d,row,col);
	}

	else if(shape==5)
	{
		TBlock->Move(rotate,d,row,col);

	}

	else if(shape==6)
	{
		IBlock->Move(rotate,d,row,col);

	}

}

int Tetromino :: Print(int shape, int rotate, int row, int col,WINDOW *win1)
{
	if(shape==0) //네모
	{
		return OBlock->SavePrint(row,col,win1);
	}

	else if(shape==1) //L
	{
		return LBlock->SavePrint(rotate,row,col,win1);
	}

	else if(shape==2)
	{
		return JBlock->SavePrint(rotate,row,col,win1);
	}

		else if(shape==3)
	{
		return SBlock->SavePrint(rotate,row,col,win1);
	}

		else if(shape==4)
	{
		return ZBlock->SavePrint(rotate,row,col,win1);
	}

		else if(shape==5)
	{
		return TBlock->SavePrint(rotate,row,col,win1);
	}

	else if(shape==6)
	{
		return IBlock->SavePrint(rotate,row,col,win1);
	}
	else
		return 0;
}

int Tetromino::Input(int shape, int rotate, int row, int col)
{
	if(shape==0) //네모
	{
		return OBlock->Save(row,col);
	}

	else if(shape==1) //L
	{
		return LBlock->Save(rotate,row,col);
	}

	else if(shape==2)
	{
		return JBlock->Save(rotate,row,col);
	}

	else if(shape==3)
	{
		return SBlock->Save(rotate,row,col);
	}

	else if(shape==4)
	{
		return ZBlock->Save(rotate,row,col);
	}

	else if(shape==5)
	{
		return TBlock->Save(rotate,row,col);
	}

	else if(shape==6)
	{
		return IBlock->Save(rotate,row,col);
	}
	else
		return 0;
}





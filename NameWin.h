#ifndef NAMEEBOARD_H
#define NAMEBOARD_H


#include <curses.h>
#include <cstring>

using namespace std;

class NameWin 
{	
private:
	char name[10];
public:
	NameWin(char *name)
	{ 
		strcpy(this->name,name);  
	} // �̸�����
	void PrintWin(); // �̸�â ���

};


#endif
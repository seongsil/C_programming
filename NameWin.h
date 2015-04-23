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
	} // 이름설정
	void PrintWin(); // 이름창 출력

};


#endif
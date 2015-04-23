#include"NameWin.h"
#include <curses.h>

void NameWin::PrintWin()
{
	WINDOW *win3;
	win3=newwin(4,10,10,30);               
	wborder(win3,'|','|','-','-','+','+','+','+');                
	mvwprintw(win3,1,1,"name:");
	mvwprintw(win3,2,1,"%s",name);                     
	wrefresh(win3);                                
}
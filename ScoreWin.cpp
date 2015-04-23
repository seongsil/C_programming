
#include "ScoreWin.h"
#include <curses.h>


void ScoreWin::PrintWin()
{
		WINDOW *win2; 
		win2=newwin(4,10,4,30);                
		wborder(win2,'|','|','-','-','+','+','+','+');                    
		mvwprintw(win2,1,1,"Score: ");               
		mvwprintw(win2,2,1,"%d",score);
		wrefresh(win2);  
}
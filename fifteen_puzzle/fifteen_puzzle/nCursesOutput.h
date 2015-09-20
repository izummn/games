#include <iostream>
#include "logic.h"
#include "curses.h"
#include <string>

using namespace std;

class nCursesOutput
{
private:
	Logic lgc;

public:
	nCursesOutput()
	{ 
		initscr(); 
		keypad(stdscr, true);
	}
	~nCursesOutput()
	{
		keypad(stdscr, false);
		endwin(); 
	}

	void start()
	{	
		int input;
		printw(" ***** Fifteen puzzle ***** \n");
		printw(" To start game press <n> key. \n");
		printw(" To exit from game press <q> key. \n");
		printw(" To restart game press <r> key. \n");
		refresh();
		lgc.newGame();
		while (checkInput(getch()))
		{
			if (lgc.winCheck())
			{
				printw(" You win! \n");
				printw(" To start new game press <n> key. \n");
				printw(" To exit from game press <q> key. \n");
				refresh();
			}
			else
			show();	
		}
		
	}

	bool checkInput(int p)
	{
		clear();
		switch (p)
		{
		case static_cast<int>('w'):   { lgc.setValue(MOVE_UP); return true; }  break;
		case static_cast<int>('s'):   { lgc.setValue(MOVE_DOWN); return true; }  break;
		case static_cast<int>('a'):   { lgc.setValue(MOVE_LEFT); return true; }  break;
		case static_cast<int>('d'):   { lgc.setValue(MOVE_RIGHT); return true; } break;
		case static_cast<int>('n'):   { lgc.newGame(); return true; } break;
		case static_cast<int>('r'):   { lgc.resetPuzzle(); return true; }  break;
		case static_cast<int>('q'): 	return false; break;

		case KEY_UP:     { lgc.setValue(MOVE_UP); return true; }  break;
		case KEY_DOWN:   { lgc.setValue(MOVE_DOWN); return true; }  break;
		case KEY_LEFT:   { lgc.setValue(MOVE_LEFT); return true; }  break;
		case KEY_RIGHT:  { lgc.setValue(MOVE_RIGHT); return true; } break;
		}
		printw(" Error! Try again! ");
		return true;
	}

	void show()
	{
		for (int i(0); i < lgc.getPsize(); i++)
		{
			printw("\n");
			for (int j(0); j < lgc.getPsize(); j++)
				if (lgc.getArr(i, j) == 0)
					printw("   ");
				else
					printw("%3d", lgc.getArr(i, j));		
		}
	}

};



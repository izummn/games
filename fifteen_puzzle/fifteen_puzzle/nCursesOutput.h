#pragma once
#include <iostream>
#include "logic.h"
#include <conio.h>
#include "curses.h"
#include <string>

using namespace std;

class nCursesOutput
{
private:
	Logic lgc;

public:
	nCursesOutput(){ initscr(); }
	~nCursesOutput(){ endwin(); }

	void start()
	{
		
		char input;
		printw(" ***** Fifteen puzzle ***** \n");
		printw(" To start game press <n> key. \n");
		printw(" To exit from game press <q> key. \n");
		printw(" To restart game press <r> key. \n");
		refresh();
		input = getch();

		while (checkInput(input))
		{
			if (lgc.winCheck())
			{
				printw(" You win! \n");
				break;
			}
			show();
			input = getch();
		}
		
	}

	bool checkInput(char p)
	{
		clear();
		refresh();
		switch (p)
		{
		case 'w':   { lgc.setValue(MOVE_UP); return true; }  break;
		case 's':   { lgc.setValue(MOVE_DOWN); return true; }  break;
		case 'a':   { lgc.setValue(MOVE_LEFT); return true; }  break;
		case 'd':   { lgc.setValue(MOVE_RIGHT); return true; } break;
		case 'n':   { lgc.newGame(); return true; } break;
		case 'r':   { lgc.resetPuzzle(); return true; }  break;
		case 'q':	return false; break;
		}
		printw(" Error! Try again! ");
		return true;
	}


	void show()
	{
		char s[10];
		for (int i(0); i < lgc.getPsize()*lgc.getPsize(); i++)
		{
			if (i % lgc.getPsize() == 0)
				printw("\n");
			if (lgc.getArr(i) == 0)
				printw("   ");
			else
			{
				_itoa_s(lgc.getArr(i), s, 10);
				printw("%3s",s);
			}
		}
	}

};



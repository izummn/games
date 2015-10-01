#include <iostream>
#include "logic.h"
#include "curses.h"
//#include "Saver.h"
#include <string>

using namespace std;

class nCursesOutput	// :public Saver
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
		endwin(); 
	}

	Logic getLgc() const { return lgc; }

	void run()
	{	
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
		case static_cast<int>('w') : case KEY_UP:     lgc.setValue(MOVE_UP);    break;
		case static_cast<int>('s') : case KEY_DOWN:   lgc.setValue(MOVE_DOWN);  break;
		case static_cast<int>('a') : case KEY_LEFT:   lgc.setValue(MOVE_LEFT);  break;
		case static_cast<int>('d') : case KEY_RIGHT:  lgc.setValue(MOVE_RIGHT); break;
		case static_cast<int>('n'):					  lgc.newGame();		    break;
		case static_cast<int>('r'):					  lgc.resetPuzzle();        break;
		case static_cast<int>('q'): 				  return false;
	    default:							  printw(" Error! Try again! ");	break;
		//default:							  throw std::exception();	break;
		}
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







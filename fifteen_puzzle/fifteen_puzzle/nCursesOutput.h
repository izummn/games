#include <iostream>
#include "logic.h"
#include "curses.h"
#include <string>


using namespace std;

class nCursesOutput
{
private:
	Logic lgc;
	Saver svr;

public:
	nCursesOutput() :svr()
	{ 
		initscr(); 
		keypad(stdscr, true);
	}

	nCursesOutput(const string& v_s) :svr(v_s)
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
		printw(" To save game press <p> key. \n");
		printw(" To open game press <o> key. \n");
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
		case static_cast<int>('p') :				  saveMenu();				break;
		case static_cast<int>('o') :				  readMenu();				 break;
		case static_cast<int>('q'): 				  return false;
	    default:							  printw(" Error! Try again! ");	break;
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

	void saveMenu()
	{
		char* s = new char[100];
		s[0] = '\0';
		printw(" Enter file name: ");
		scanw("%99s", s);
		if (s[0] != '\0') svr.setFileName(s);
		svr.saveToFile(lgc);
		printw(" Saved to file: %s", svr.getFileName().c_str());
	}

	void readMenu()
	{
		char* s = new char[100];
		printw(" Enter file name: ");
		scanw("%99s", s);
		svr.setFileName(s);
		if (!svr.readFile(lgc)) printw(" File not found, try again! ");
	}
};







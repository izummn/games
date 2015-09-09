#include <iostream>
#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class ConsoleOuputSystem
{
private:
	Logic lgc;
public:
	ConsoleOuputSystem(){}
	~ConsoleOuputSystem(){}

	void start()
	{
		char input;
		cout << " ***** Fifteen puzzle ***** " << endl;
		cout << " To start game press <n> key. " << endl;
		cout << " To exit from game press <q> key. " << endl;
		cout << " To restart game press <r> key. " << endl;
		cin >> input;

		while (checkInput(input))
		{
			system("cls");
			cout << *this << endl;
			input = _getch();

			if (lgc.winCheck())
			{
				cout << " You win! " << endl;
				break;
			}		
		}
	}

	bool checkInput(char p)
	{
		switch (p)
		{
		case 'w':   lgc.setValue(MOVE_UP);  break;
		case 's':   lgc.setValue(MOVE_DOWN);  break;
		case 'a':   lgc.setValue(MOVE_LEFT);  break;
		case 'd':   lgc.setValue(MOVE_RIGHT);  break;
		case 'n':   lgc.mixPuzzle(); break;
		case 'q':  return false; break;
		case 'r':  /* to do */   break;
		}
			//cout << " Error! Try again! " << endl;
			return true; 
	}

	friend ostream& operator<<(ostream &os, ConsoleOuputSystem &obj)
	{
		
		for (int i(0); i < 4; i++)
		{
			os << endl;
			for (int j(0); j < 4; j++)
			{
				os.width(4);
				if (obj.lgc.getArr(i,j) == 0)
					os << "   ";
				else
					os << obj.lgc.getArr(i, j);
			}
		}
		return os;
	}

};



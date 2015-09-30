#include <iostream>
#include "logic.h"
#include <conio.h>

using namespace std;

class ConsoleOuputSystem
{
private:
	Logic lgc;

public:
	ConsoleOuputSystem(){}
	~ConsoleOuputSystem(){}

	void run()
	{
		char input;
		cout << " ***** Fifteen puzzle ***** " << endl;
		cout << " To start game press <n> key. " << endl;
		cout << " To exit from game press <q> key. " << endl;
		cout << " To restart game press <r> key. " << endl;
		cin >> input;

		while (checkInput(input))
		{
			if (lgc.winCheck())
			{
				cout << " You win! " << endl;
				cout << " To start game press <n> key. " << endl;
				cout << " To exit from game press <q> key. " << endl;
			}
			else
				cout << *this << endl;

			input = _getch();
		}
	}

	bool checkInput(char p)
	{
		system("cls");
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
		cout << " Error! Try again! " << endl;
		return true; 
	}


	friend ostream& operator<<(ostream &os, ConsoleOuputSystem &obj)
	{
		
		for (int i(0); i < obj.lgc.getPsize(); i++)
		{
			os << endl;
			for (int j(0); j < obj.lgc.getPsize(); j++)
			{
				os.width(4);
				if (obj.lgc.getArr(i, j) == 0)
					os << "   ";
				else
					os << obj.lgc.getArr(i, j);
			}
		}
		return os;
	}

};



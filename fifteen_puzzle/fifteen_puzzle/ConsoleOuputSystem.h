#pragma once
#include <iostream>
#include "logic.h"
#include <conio.h>
#include "Saver.h"

using namespace std;

class ConsoleOuputSystem : private Saver
{
private:
	Logic lgc;

public:
	ConsoleOuputSystem(){}
	ConsoleOuputSystem(const string v_s):Saver(v_s){}
	~ConsoleOuputSystem(){}

	void run()
	{
		char input;
		cout << " ***** Fifteen puzzle ***** " << endl;
		cout << " To start game press <n> key. " << endl;
		cout << " To exit from game press <q> key. " << endl;
		cout << " To restart game press <r> key. " << endl;
		cout << " To save game press <p> key. " << endl;
		cout << " To open game press <o> key. " << endl;
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
		case 'w':    lgc.setValue(MOVE_UP);		 break;
		case 's':    lgc.setValue(MOVE_DOWN);    break;
		case 'a':    lgc.setValue(MOVE_LEFT);    break;
		case 'd':    lgc.setValue(MOVE_RIGHT);   break;
		case 'n':    lgc.newGame();				 break;
		case 'r':    lgc.resetPuzzle();			 break;
		case 'p':    saveMenu();				 break;
		case 'o':    readMenu();				 break;
		case 'q':	 return false; 
		default:	 cout << " Error! Try again! " << endl; break;
		}
		return true; 
	}

	void saveMenu()
	{
		cout << " Save to file: " << endl;
		string s;
		cin >> s;
		setFileName(s);
		saveToFile(lgc);
		cout << " Success! Saved to file: " << getFileName() << endl;
	}

	void readMenu()
	{
		cout << " Load from file: " << endl;
		string s;
		cin >> s;
		setFileName(s); 
		readFile(lgc);
		
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



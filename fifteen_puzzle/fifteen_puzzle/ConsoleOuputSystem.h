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
	ConsoleOuputSystem()
	{
		Logic obj;
		lgc = obj;
	};
	~ConsoleOuputSystem(){};

	void start()
	{
		cout << *this;
		char input;

		do{
			cout << endl;
			input = _getch();
			//input = stdin.get();
			//system("cls");
			lgc.setValue(input);
			cout << *this;
		} while (input != 'q');
	};


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



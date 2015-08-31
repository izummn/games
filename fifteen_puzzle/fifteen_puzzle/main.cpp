#include <iostream>
#include "ConsoleOuputSystem.h"
#include <conio.h>

using namespace std;

int main()
{
	Interface A;
	cout << A;
	char input;
	do{
		cout << endl;
		input = _getch();
		system("cls");
		A.setValue(input);
		cout << A;
	} while (input != 'q');

	return 0;
}


#include <iostream>
#include "ConsoleOuputSystem.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	ConsoleOuputSystem A;
	cout << A;
	char input;
	do{
		cout << endl;
		input = _getch();
		//input = stdin.get();
		//system("cls");
		A.setValue(input);
		cout << A;
	} while (input != 'q');

	return 0;
}


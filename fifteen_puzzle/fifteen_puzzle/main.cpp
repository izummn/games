#include <iostream>
#include "ConsoleOuputSystem.h"
#include <curses.h>

using namespace std;

int main()
{
	//initscr();
	ConsoleOuputSystem* A = new ConsoleOuputSystem[2];
	A[0].start();
	//A[1].start();
	delete[] A;
	return 0;
}


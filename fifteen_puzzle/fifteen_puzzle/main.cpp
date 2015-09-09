#include <iostream>
#include "ConsoleOuputSystem.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	ConsoleOuputSystem* A = new ConsoleOuputSystem[1];
	A->start();
	delete[] A;
	return 0;
}


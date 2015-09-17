#pragma once
#include <iostream>
#include "ConsoleOuputSystem.h"
#include "nCursesOutput.h"
#include <conio.h>


using namespace std;

int main()
{
	//ConsoleOuputSystem* A = new ConsoleOuputSystem[1];
	nCursesOutput* A = new nCursesOutput[1];
	A->start();
	delete[] A;
	return 0;
}


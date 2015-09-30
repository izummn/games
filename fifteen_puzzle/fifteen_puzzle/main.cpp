#include <iostream>
#include "ConsoleOuputSystem.h"
#include "nCursesOutput.h"
#include <exception>  


using namespace std;

int main()
{
	//ConsoleOuputSystem* A = new ConsoleOuputSystem[1];
	nCursesOutput* A = new nCursesOutput[1];
	try
	{
		A->run();
	}
	catch (std::exception& UnknownKey)
	{
		cout << "Error key! " << endl;
	};
	delete[] A;
	return 0;
}


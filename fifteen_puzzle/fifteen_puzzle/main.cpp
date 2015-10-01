#include <iostream>
#include "ConsoleOuputSystem.h"
#include "nCursesOutput.h"
#include <exception>  


using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Enter mode!" << std::endl;
		exit(1);
	}

	string mode(argv[1]);

try
{

	if (mode == "-ui=console")
	{
		ConsoleOuputSystem* A = new ConsoleOuputSystem[1];
		A->run();
		delete[] A;
	}
	else
	{
		nCursesOutput* A = new nCursesOutput[1];
		A->run();
		delete[] A;
	}		
}
catch (std::exception& UnknownKey)
{
	cout << "Error key! " << endl;
};
	
	return 0;
}


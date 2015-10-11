#include <iostream>
#include "ConsoleOuputSystem.h"
#include "nCursesOutput.h"
#include <boost/program_options.hpp> 
#include <exception>  


using namespace std;


/*int main(int argc, char *argv[])
{


	int opt;
	namespace po = boost::program_options;
	po::options_description desc("Allowed options");
	desc.add_options()
		("ui,I", po::value<std::string>(), "Input interface");
*/


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Enter mode!" << std::endl;
		exit(1);
	}

	string mode(argv[1]);
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

	
	return 0;
}


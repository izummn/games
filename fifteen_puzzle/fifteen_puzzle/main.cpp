#include <iostream>
#include "ConsoleOuputSystem.h"
#include "nCursesOutput.h"
#include <boost/program_options.hpp> 
#include <exception>  


using namespace std;


int main(int argc, char *argv[])
//int main()
{

/*if (argc < 2)
	{
		std::cout << "Enter mode!" << std::endl;
		exit(1);
	}*/
		namespace po = boost::program_options;
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", " produce help message ")
			("uI", po::value<string>(), " set user interface nCurses or console ")
			("fN", po::value<string>(), " set fileName (optional) ");

		po::variables_map vm;
		ifstream p("file.ini");

		store(parse_config_file(p, desc), vm);
		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);

		string s = vm["fN"].as<string>();
		if (vm.count("help"))
		{
			cout << desc << "\n";
			return 1;
		}

		if (vm["uI"].as<string>() == "console")
		{
			ConsoleOuputSystem* A = new ConsoleOuputSystem(s);
			A->run();
			delete A;
		}

		if (vm["uI"].as<string>() == "nCurses")
		{
			nCursesOutput* A = new nCursesOutput(s);
			A->run();
			delete A;
		}


	return 0;
}


#include <iostream>
#include "ConsoleOuputSystem.h"
#include "nCursesOutput.h"
#include <boost/program_options.hpp> 
#include <exception>  
#include "IOutputSystem.h"


using namespace std;

//1

int main(int argc, char *argv[])
{
		namespace po = boost::program_options;
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", " produce help message ")
			("uI", po::value<string>(), " set user interface nCurses or console ")
			("fN", po::value<string>(), " set fileName (optional) ");

		po::variables_map vm;
		ifstream p("file.ini");

		if (argc < 2)  store(parse_config_file(p, desc), vm);
		else store(parse_command_line(argc, argv, desc), vm);

		notify(vm);
		string s("fifteen_puzzle.txt");

		if (vm.count("help"))
		{
			cout << desc << "\n";
			return 1;
		}

		 if (vm.count("fN"))
			 s = vm["fN"].as<string>();

		 IOutputSystem* outputSystem = NULL;
		 if (vm["uI"].as<string>() == "console")
			 outputSystem = new ConsoleOuputSystem(s);
		 else if (vm["uI"].as<string>() == "nCurses")
			 outputSystem = new nCursesOutput(s);
		 else
		 {
			 cout << "wrong output system" << endl;
			 delete outputSystem;
			 return 0;
		 }
		 outputSystem->run();
		 delete outputSystem;

	return 0;
}


#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;


class Saver
{
private:
	std::string fileName;

public:
	Saver(){}
	Saver(std::string v_fileName) : fileName(v_fileName) {}

	void saveFile()
	{
		ptree puzzleTree;
		for (int i(0); i < pSize /* getPsize */; i++)
			puzzleTree.put(std::to_string(i), std::to_string( /* getArr(i, j)  */  ));

		json_parser::write_json(fileName, puzzleTree);
	};

	void readFile()
	{
		ptree puzzleTree;
		json_parser::read_json(fileName, puzzleTree);

		// Create object nCurses or start run() ?

	};

	~Saver(){}

};

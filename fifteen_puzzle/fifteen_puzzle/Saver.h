#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;


class Saver
{
private:
	std::string fileName;

public:
	Saver() : fileName("test") {}
	Saver(std::string v_fileName) : fileName(v_fileName) {}

	void saveToFile(const Logic& lgc)
	{
		ptree puzzleTree;
		for (int i(0); i < lgc.getPsize()*lgc.getPsize(); i++)
			puzzleTree.put(std::to_string(i), std::to_string(lgc.getArr(i)));
		json_parser::write_json(fileName, puzzleTree);
	};

	bool readFile(Logic& lgc)
	{
		ptree puzzleTree;
		json_parser::read_json(fileName, puzzleTree);
		for (int i(0); i < lgc.getPsize()*lgc.getPsize(); i++)
			lgc.setArr(i, std::stoi(puzzleTree.get<std::string>(std::to_string(i))));
		lgc.saveTempPuzzle();
		return true;
	};

	~Saver(){}

};

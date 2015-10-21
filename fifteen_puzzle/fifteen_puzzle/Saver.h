#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

using namespace boost::property_tree;


class Saver
{
private:
	std::string fileName;

public:
	Saver() : fileName("fifteen_puzzle.txt") {}
	Saver(std::string v_fileName) : fileName(v_fileName) {}

	void setFileName(const string &v_s){	 fileName = v_s; }
	string getFileName() const { return fileName; }

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
		if (!boost::filesystem::exists(fileName)) return false;
		json_parser::read_json(fileName, puzzleTree);
		for (int i(0); i < lgc.getPsize()*lgc.getPsize(); i++)
			lgc.setArr(i, std::stoi(puzzleTree.get<std::string>(std::to_string(i))));
		lgc.saveTempPuzzle();
		return true;
	};

	~Saver(){}

};

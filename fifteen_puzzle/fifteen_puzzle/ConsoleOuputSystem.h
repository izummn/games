#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class ConsoleOuputSystem
{
private:
	int arr[4][4];
	int curr;
public:
	ConsoleOuputSystem()
	{
		int n(1);
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
			{
				arr[i][j] = n;
				n++;
			}
		arr[3][3] = 0;
		curr = 0;
	}
	//~Interface(){};

	bool setValue(const char v_action)
	{
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
				if (arr[i][j] == curr)

				{

			switch (v_action)
			{
			case 'w':		//up
			{
				if (i > 0)
					curr = arr[i - 1][j];
				return true;
			}
				break;

			case 'a':		//left
			{
				if (j > 0)
					curr = arr[i][j - 1];
				return true;
			}
				break;

			case 's':		//down
			{
				if (i < 3)
					curr = arr[i + 1][j];
				return true;
			}
				break;

			case 'd':		//right
			{
				if (j < 3)
					curr = arr[i][j + 1];
				return true;
			}
				break;

			case 'r':		//SET
			{
				if ((arr[i - 1][j] == 0) && (i > 0)) swap(arr[i][j], arr[i - 1][j]);
				if ((arr[i + 1][j] == 0) && (i < 3)) swap(arr[i][j], arr[i + 1][j]);
				if ((arr[i][j - 1] == 0) && (j > 0)) swap(arr[i][j], arr[i][j - 1]);
				if ((arr[i][j + 1] == 0) && (j < 3)) swap(arr[i][j], arr[i][j + 1]);
				return true;
			}
				break;
			}
				}
		return true;
	};

	friend ostream& operator<<(ostream &os, const ConsoleOuputSystem &obj)
	{
		for (int i(0); i < 4; i++)
		{
			os << endl;
			for (int j(0); j < 4; j++)
			{
				if (obj.arr[i][j] == obj.curr)
				{
					os << "[";
					os.width(2);
					if (obj.arr[i][j] == 0)
						os << "  ]";
					else
						os << obj.arr[i][j] << "]";
				}
				else
				{
					os.width(4);
					if (obj.arr[i][j] == 0)
						os << "  ";
					else 
						os << obj.arr[i][j];
				}
			}
		}
		return os;
	}


};



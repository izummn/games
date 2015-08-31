#include <iostream>;

using namespace std;

class Interface
{
private:
	int arr[4][4];
	//char action;
public:
	Interface()
	{
		int n(1);
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
			{
			arr[i][j] = n;
			//arr[i][j] = 1;
			n++;
			}
		arr[3][3] = 0;
	}
	//~Interface(){};

	bool setValue(const char v_action)
	{
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
				if (arr[i][j] == 0)
				{

			switch (v_action)
			{
			case 'w':		//up
			{
				if (i > 0)
					swap(arr[i][j], arr[i - 1][j]);
				return true;
			}
				break;

			case 'a':		//left
			{
				if (j > 0)
					swap(arr[i][j], arr[i][j - 1]);
				return true;
			}
				break;

			case 's':		//down
			{
				if (i < 3)
					swap(arr[i][j], arr[i + 1][j]);
				return true;
			}
				break;

			case 'd':		//right
			{
				if (j < 3)
					swap(arr[i][j], arr[i][j + 1]);
				return true;
			}
				break;
			}
				}
		return true;
	};

	friend ostream& operator<<(ostream &os, const Interface &obj)
	{
		for (int i(0); i < 4; i++)
		{
			os << endl;
			for (int j(0); j < 4; j++)
			{
				os.width(3);
				os << obj.arr[i][j];
			}
		}
		return os;
	}

};

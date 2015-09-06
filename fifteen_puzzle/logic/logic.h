#include <iostream>
using namespace std;

class Logic
{
private:
	int arr[4][4];
	
public:
	Logic()
	{
		int n(1);
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
			{
			arr[i][j] = n;
			n++;
			}
		arr[3][3] = 0;
	}
	~Logic(){};
	int getArr(int v_i, int v_j)
	{
		return arr[v_i][v_j];
	}

	bool setValue(const char v_action)
	{
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
				if (arr[i][j] == 0)

				{

			switch (v_action)
			{
			case 's':		//down
			{
				if (i > 0)
					swap(arr[i][j], arr[i - 1][j]);
				return true;
			}
				break;

			case 'd':		//right
			{
				if (j > 0)
					swap(arr[i][j], arr[i][j - 1]);

				return true;
			}
				break;

			case 'w':		//up
			{
				if (i < 3)
					swap(arr[i][j], arr[i + 1][j]);
				return true;
			}
				break;

			case 'a':		//left
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
};
#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib> 
#include <vector>
using namespace std;

enum action{ MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };
const int pSize = 4;

class Logic
{
private:
	int arr[pSize][pSize];
	int temp[pSize][pSize];
	//int** arr;

public:
	Logic()
	{
		/*int **arr = new int*[pSize];
			for (int i(0); i < pSize; i++)
				arr[i] = new int[pSize];*/

		int n(1);
		for (int i(0); i < pSize; i++)
			for (int j(0); j < pSize; j++)
			{
				arr[i][j] = n;
				temp[i][j] = n;
				n++;
			}
		arr[pSize-1][pSize-1] = 0;
		temp[pSize - 1][pSize - 1] = 0;
	}

	Logic(const Logic &obj)
	{
	/*	int **arr = new int*[pSize];
		for (int i(0); i < pSize; i++)
			arr[i] = new int[pSize];*/

		for (int i(0); i < pSize; i++)
			for (int j(0); j < pSize; j++)
			arr[i][j] = obj.arr[i][j];
	}

	~Logic()
	{
	 /*  for (int i(0); i < pSize; i++)
			delete[] arr[i];
		  delete[] arr;
		  */
	};

	int getArr(int v_i, int v_j) const
	{
		return arr[v_i][v_j];
	}

	void setValue(const action v_action)
	{
		for (int i(0); i < pSize; i++)
			for (int j(0); j < pSize; j++)
				if (arr[i][j] == 0)

				{

			switch (v_action)
			{
			case MOVE_DOWN:		
			{
				if (i > 0)
					swap(arr[i][j], arr[i - 1][j]);
				return;
			}
				break;

			case MOVE_RIGHT:		
			{
				if (j > 0)
					swap(arr[i][j], arr[i][j - 1]);

				return;
			}
				break;

			case MOVE_UP:		
			{
				if (i < (pSize-1))
					swap(arr[i][j], arr[i + 1][j]);
				return;
			}
				break;

			case MOVE_LEFT:		
			{
				if (j < (pSize-1))
					swap(arr[i][j], arr[i][j + 1]);
				return;
			}
				break;
			}
				}
	};

	bool operator==(const Logic &l) const
	{
		for (int i(0); i < pSize; i++)
			for (int j(0); j < pSize; j++)
			if (arr[i][j] != l.arr[i][j]) return false;
		return true;
	}


	Logic& operator=(const Logic& obj)
	{
		/*int **arr = new int*[pSize];
		for (int i(0); i < pSize; i++)
			arr[i] = new int[pSize];
			*/

		for (int i(0); i < pSize; i++)
			for (int j(0); j < pSize; j++)
				arr[i][j] = obj.arr[i][j];
		return *this;
	}

	bool winCheck() const
	{
		Logic l;
		return (*this) == l;
	}

	void mixPuzzle()
	{
		std::vector<int> p(pSize*pSize);
		int e(0);
		for (int i(0); i < pSize*pSize; i++)
			p[i] = i;
		std::srand(unsigned(std::time(0)));
		random_shuffle(p.begin(), p.end());

		for (int i(0); i < pSize*pSize; i++)
			if (p[i] == 0) e = i / pSize + 1;
				
		if (hasNoSolution(p, e))
		{
			Logic sw = *this;
			for (int i(0); i < pSize; i++)
				for (int j(0); j < pSize; j++)
					arr[j][pSize - 1 - i] = sw.arr[i][j];
		}

		int n(0);

		for (int i(0); i < pSize; i++)
			for (int j(0); j < pSize; j++)
			{
				arr[i][j] = p[n];
				n++;
			}
	}

	static bool hasNoSolution(const std::vector<int> &p, int e)
	{
		int t(0), sum(e);
		for (int i(1); i < pSize*pSize; i++)
		{
			for (int j(i); j < pSize*pSize; j++)
				if (p[i] < p[j]) t++;
			sum += t;
			t = 0;
		}
		if (sum % 2 == 0) return false;
		else return true;
	}

	void newGame()
	{
		mixPuzzle();
		for (int i(0); i < pSize; i++)
			for (int j(0); j < pSize; j++)
				temp[i][j] = arr[i][j];
	}

	void resetPuzzle()
	{
		for (int i(0); i < pSize; i++)
			for (int j(0); j < pSize; j++)
				arr[i][j] = temp[i][j];
	}

};
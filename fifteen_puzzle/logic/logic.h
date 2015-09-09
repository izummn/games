#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib> 
#include <vector>
using namespace std;

enum action{ MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };


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
	void setValue(const char v_action)
	{
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
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
				if (i < 3)
					swap(arr[i][j], arr[i + 1][j]);
				return;
			}
				break;

			case MOVE_LEFT:		
			{
				if (j < 3)
					swap(arr[i][j], arr[i][j + 1]);
				return;
			}
				break;
			}
				}
	};
	bool operator==(const Logic &l)
	{
		int n(1);
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
			{
			if (arr[i][j] != n) return false;
			n++;
			if (n == 16) n = 0;
			}
		return true;
	}
	bool winCheck()
	{
		Logic l;
		return (*this) == l;
	}
	void mixPuzzle()
	{
		std::vector<int> p;
		int e(0);
		do {
			p.clear();
			for (int i(0); i < 16; i++)
				p.push_back(i);
			std::srand(unsigned(std::time(0)));
			random_shuffle(p.begin(), p.end());

			for (int i(0); i < 16; i++)
				if (p[i] == 0) e = i / 4 + 1;
		} while (checkSolution(p, e));

		int n(0);
		for (int i(0); i < 4; i++)
			for (int j(0); j < 4; j++)
			{
				arr[i][j] = p[n];
				n++;
			}
	}
	bool checkSolution(std::vector<int> &p, int &e)
	{
		int t(0), sum(e);
		for (int i(1); i < 16; i++)
		{
			for (int j(i); j < 16; j++)
				if (p[i] < p[j]) t++;
			sum += t;
			t = 0;
		}
		return !(sum % 2);
	}

};
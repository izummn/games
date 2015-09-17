#pragma once
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
	const int pSize;
	std::vector<int> arr;
	std::vector<int> temp;
public:
	Logic():pSize(4)
	{
		int n(1);
		for (int i(0); i < pSize*pSize; i++)
		{
			arr.push_back(n);
			temp.push_back(n);
			n++;
		}
		arr[pSize*pSize-1]= 0;
		temp[pSize*pSize - 1] = 0;
	}
	int getPsize() { return pSize; }

	Logic(const Logic &obj) :pSize(4)
	{
			arr = obj.arr;
			temp = obj.temp;
	}

	~Logic()
	{};

	int getArr(int v_i) const
	{
		return arr[v_i];
	}

	void setValue(const action v_action)
	{
		for (int i(0); i < pSize*pSize; i++)
				if (arr[i] == 0)

				{

			switch (v_action)
			{
			case MOVE_DOWN:		
			{
				if (i >= pSize)
					swap(arr[i], arr[i - pSize]);
				return;
			}
				break;

			case MOVE_LEFT:		
			{
				if (i%pSize != pSize-1)
					swap(arr[i], arr[i + 1]);

				return;
			}
				break;

			case MOVE_UP:		
			{
				if (i <  pSize*pSize - pSize)
					swap(arr[i], arr[i + pSize]);
				return;
			}
				break;

			case MOVE_RIGHT:
			{
				if (i%pSize != 0)
					swap(arr[i], arr[i - 1]);
				return;
			}
				break;
			}
				}
	};

	bool operator==(const Logic &l) const
	{
		for (int i(0); i < pSize*pSize; i++)
			if (arr[i] != l.arr[i]) return false;
		return true;
	}

	bool winCheck() const
	{
		Logic l;
		return (*this) == l;
	}

	void mixPuzzle()
	{
		int e(0);
			for (int i(0); i < pSize*pSize; i++)
				arr[i] = i;
			std::srand(unsigned(std::time(0)));
			random_shuffle(arr.begin(), arr.end());

			for (int i(0); i < pSize*pSize; i++)
				if (arr[i] == 0) e = i / pSize + 1;

			if (hasNoSolution(e))
				swap(arr[pSize*pSize - 1], arr[pSize*pSize - 2]);
	}

	 bool hasNoSolution(int e) const
	{
		int t(0), sum(e);
		for (int i(1); i < pSize*pSize; i++)
		{
			for (int j(i); j < pSize*pSize; j++)
				if (arr[i] < arr[j]) t++;
			sum += t;
			t = 0;
		}
		if (sum % 2 == 0) return false;
		else return true;
	}

	void newGame()
	{
		mixPuzzle();
		temp = arr;
	}

	void resetPuzzle()
	{
		arr = temp;
	}
	
};
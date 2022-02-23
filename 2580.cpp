#include <bits/stdc++.h>
#define FASTIO		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int puzzle[9][9];
stack<int> xs;
stack<int> ys;
int isSudokuPossible(int zerox, int zeroy, int num)
{

	// Á÷¼±
	for (int i = 0; i < 9; ++i)
	{
		if (puzzle[zeroy][i] == num)
			return false;
		if (puzzle[i][zerox] == num)
			return false;
	}

	//Ä­ ¾È¿¡
	int areax = zerox / 3 * 3;
	int areay = zeroy / 3 * 3;
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col) {
			if (puzzle[areay + row][areax + col] == num)
				return false;
		}
	}

	return true;
}

void sudoku()
{
	if (xs.empty())
	{
		throw true;
	}
	int nowx = xs.top();
	int nowy = ys.top();
	for (int i = 1; i < 10; ++i)
	{

		if (isSudokuPossible(nowx, nowy, i)) {
			puzzle[nowy][nowx] = i;
			ys.pop();
			xs.pop();
			sudoku();
			xs.push(nowx);
			ys.push(nowy);
			puzzle[nowy][nowx] = 0;
		}
	}
}

int main()
{
	FASTIO;
	for (int row = 0; row < 9; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{
			int number;
			cin >> number;
			if (number == 0) {
				xs.push(col);
				ys.push(row);
			}	 
			puzzle[row][col] = number;
		}
	}
	try {
		sudoku();
	}
	catch (...)
	{
		for (int row = 0; row < 9; ++row)
		{
			for (int col = 0; col < 9; ++col)
			{
				cout << puzzle[row][col] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;

}

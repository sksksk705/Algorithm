#include <bits/stdc++.h>

using namespace std;

bool board[15][15];
int board_size;
int factorial(int n)
{
	int result = 1;

	for (int i = 1; i <= n; ++i)
		result *= i;

	return result;
}

bool canPut(int x, int y)
{
	//세로에 퀸이 있는가?
	for (int row = 0; row < board_size; ++row)
	{
		if (board[row][x]) {
			return false;
		}
	}

	//가로에 퀸이 있는가?
	for (int col = 0; col < board_size; ++col)
	{
		if (board[y][col]) {
			return false;
		}
	}

	//양쪽 대각선에 퀸이 있는가?
	//왼쪽 위, 오른쪽 아래, 왼쪽 아래, 오른쪽 위.
	int nextx = x-1;
	int nexty = y-1;
	while (nextx >= 0 && nexty>=0)
	{
		if (board[nexty][nextx])
			return false;
		nextx--;
		nexty--;

	}

	nextx = x+1;
	nexty = y+1;
	while (nextx < board_size && nexty < board_size)
	{
		if (board[nexty][nextx])
			return false;
		nextx++;
		nexty++;

	}

	nextx = x-1;
	nexty = y+1;
	while (nextx >= 0 && nexty < board_size)
	{
		if (board[nexty][nextx])
			return false;
		nextx--;
		nexty++;

	}

	nextx = x+1;
	nexty = y-1;
	while (nextx < board_size && nexty >= 0)
	{
		if (board[nexty][nextx])
			return false;
		nextx++;
		nexty--;

	}
	return  true;
}

int n_queen(int total_queen, int goal)
{
	int ret = 0;
	if (total_queen == goal)
		return 1;
	for (int row = 0; row < board_size; ++row) {
		for (int col = 0; col < board_size; ++col)
		{
			if (board[row][col])
				continue;
			if (canPut(col, row)) {
				board[row][col] = true;
				ret += n_queen(total_queen + 1, goal);
				board[row][col] = false;
			}
		}
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	board_size = n;
	int result = n_queen(0, n);
	cout << result / factorial(n);
}
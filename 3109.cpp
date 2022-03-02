#include <iostream>
using namespace std;

int dy[3]{ -1,0,1 };

char MAP[10000][500];
int r, c;

bool dfs(int x, int y)
{
	for (int i = 0; i < 3; ++i) {
		int nexty = y + dy[i];
		if (nexty < 0 || nexty >= r ||
			MAP[nexty][x+1] != '.')
			continue;
		MAP[nexty][x + 1] = '#';
		if (x + 1 == c - 1)
			return true;
		if (dfs(x + 1, nexty))
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; ++j)
		{
			MAP[i][j] = s[j];
		}
	}
	int result = 0;
	for (int i = 0; i < r; ++i)
	{
		if (dfs(0, i))
			result++;
	}
	cout << result;
	return 0;
}
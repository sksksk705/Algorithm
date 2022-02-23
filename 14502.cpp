#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;
int n, m;

int MAP[8][8];
vector<pair<int, int>> virus;
queue<int> xq;
queue<int> yq;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void resetMAP()
 {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (MAP[i][j] == 2)
				MAP[i][j] = 0;
		}
	for (auto v : virus)
	{
		MAP[v.second][v.first] = 2;
	}
}

int HowManySafetyArea()
{
	int sa = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (MAP[i][j] == 0)
				sa++;
	return sa;
}
void dfs()
{
	for (auto v : virus)
	{
		xq.push(v.first);
		yq.push(v.second);
	}

	while (!xq.empty())
	{
		int nowx = xq.front();
		int nowy = yq.front();
		xq.pop();
		yq.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];
			if (nextx < 0 || nextx >= m ||
				nexty < 0 || nexty >= n ||
				MAP[nexty][nextx] != 0)
				continue;
			MAP[nexty][nextx] = 2;
			xq.push(nextx);
			yq.push(nexty);
		}
	}
}

int maxSafetyArea(int wall,int _x,int _y)
{
	int ret = -1;
	if (wall == 3) {
		dfs();
		int result = HowManySafetyArea();
		resetMAP();
		return result;
	}

	for (int i = _y; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (MAP[i][j] == 0)
			{
				MAP[i][j] = 1;
				ret= max(maxSafetyArea(wall + 1, j, i),ret);
				MAP[i][j] = 0;
			}
		}
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2)
				virus.push_back(make_pair(j, i));
		}

	int result = maxSafetyArea(0,0,0);
	cout << result;
}
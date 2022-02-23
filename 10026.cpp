#include <iostream>
#include <queue>
using namespace std;


int dx[4]{ -1,1,0,0 };
int dy[4]{ 0,0,-1,1 };
string MAP[101];
bool low_visited[101][101];
bool visited[101][101];
int N;
int low_result;
int result;

void dfs_low(int _x, int _y, char color)
{
	for (int i = 0; i < 4; ++i)
	{
		int nextx = _x + dx[i];
		int nexty = _y + dy[i];
		if (nextx < 0 || nextx >= N ||
			nexty < 0 || nexty >= N)
			continue;
		if (low_visited[nexty][nextx])
			continue;
		if (color == 'B')
			if (color != MAP[nexty][nextx])
				continue;
		if (MAP[nexty][nextx] != 'B') {
			low_visited[nexty][nextx] = true;
			dfs_low(nextx, nexty, color);
		}

	}
}

void dfs(int _x, int _y, char color)
{
	for (int i = 0; i < 4; ++i)
	{
		int nextx = _x + dx[i];
		int nexty = _y + dy[i];
		if (nextx < 0 || nextx >= N ||
			nexty < 0 || nexty >= N)
			continue;
		if (visited[nexty][nextx])
			continue;
		if (MAP[nexty][nextx] != color)
			continue;
		visited[nexty][nextx] = true;
		dfs(nextx, nexty, color);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> MAP[i];
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visited[i][j])
			{
				if (!low_visited[i][j]) {
					low_result++;
					low_visited[i][j] = true;
					dfs_low(j, i, MAP[i][j]);
				}
				visited[i][j] = true;
				result++;
				dfs(j, i,MAP[i][j]);
			}
		}
	}
	cout << result<<'\n'<<low_result;
}
#include <iostream>
#include <queue>
#include <set>
#include <cstring>
#define FASTIO			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
set<pair<int, int>> disappear;
int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
int board[102][102];
bool visited[102][102];
int n, m;

bool isCheese()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j] == 1)
				return true;
	return false;
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];
			if (nextx < 0 || nextx > m+1 ||
				nexty < 0 || nexty > n+1 ||
				visited[nexty][nextx])
				continue;
			if (board[nexty][nextx] == 0) {
				visited[nexty][nextx] = true;
				q.push(make_pair(nextx, nexty));
			}
			if (board[nexty][nextx] == 1)
				disappear.emplace(make_pair(nextx, nexty));
		}
	}
}

int main()
{
	FASTIO;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> board[i][j];

	int days = 0;
	int remain = 0;
	while (isCheese())
	{
		memset(visited, 0, sizeof(visited));
		disappear.clear();
		bfs(0,0);
		remain = disappear.size();
		days++;
		for (auto cheese : disappear) {
			board[cheese.second][cheese.first] = 0;
		}
	}
	cout << days << '\n' << remain;
}
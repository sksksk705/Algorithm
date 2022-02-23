#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[101][101];
int n, m, k;
int dx[4]{ -1,1,0,0 };
int dy[4]{ 0,0,-1,1 };
priority_queue<int, vector<int>, greater<int>> pq;

void bfs(int x, int y)
{
	queue<int> xq;
	queue<int> yq;
	int result = 1;
	visited[y][x] = true;
	xq.push(x);
	yq.push(y);
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
			if (visited[nexty][nextx] ||
				nextx < 0 || nextx >= m ||
				nexty < 0 || nexty >= n)
				continue;
			result++;
			visited[nexty][nextx] = true;
			xq.push(nextx);
			yq.push(nexty);
		}
	}
	pq.push(result);
}

int main()
{
	cin >> n >> m >> k;
	while (k--)
	{
		int l, t, r, b;
		cin >> l >> t >> r >> b;
		for (int i = t; i < b; ++i)
		{
			for (int j = l; j < r; j++)
			{
				visited[i][j] = true;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j])
			{
				bfs(j, i);
			}
		}
	}
	cout << pq.size()<<'\n';
	while (!pq.empty())
	{
		cout << pq.top()<<' ';
		pq.pop();
	}
}
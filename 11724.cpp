#include <bits/stdc++.h>
using namespace std;

bool visited[1001];
bool graph[1001][1001];

int main()
{
	int n, m;
	cin >> n >> m;

	int connection = 0;
	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;
		graph[start][end] = true;
		graph[end][start] = true;
	}
	for (int i = 1; i <= n; ++i)
	{
		queue<int> dfs;
		if (!visited[i]) {
			connection++;
			dfs.push(i);
		}
		while (!dfs.empty())
		{
			int start = dfs.front();
			dfs.pop();
			if (visited[start])
				continue;
			visited[start] = true;
			for (int i = 1; i <= n; ++i)
			{
				if (graph[start][i] != 0 && !visited[i])
					dfs.push(i);
			}
		}
	}
	cout << connection;
}
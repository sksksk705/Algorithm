#include <iostream>
#include <map>
#include <cstring>

using namespace std;

map<int,int> graph[10001];
bool visited[10001];
int n, m, from, to;

bool dfs(int node, int weight) {
	visited[node] = true;
	if (node == to)
		return true;
	for (auto n : graph[node])
	{
		if (visited[n.first] || weight > n.second)
			continue;
		dfs(n.first, weight);
	}
	return visited[to];
}
int main()
{

	cin >> n >> m;
	int maxC = 0;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c > maxC)
			maxC = c;
		auto it = graph[a].find(b);
		if (it != graph[a].end()) {
			graph[a][b] = max(graph[a][b], c);
			graph[b][a] = max(graph[b][a], c);
		}
		else {
			graph[a].emplace(make_pair(b, c));
			graph[b].emplace(make_pair(a, c));
		}
	}
	cin >> from >> to;
	int high = maxC;
	int low = 0;
	int ans = 0;
	while (low <= high)
	{
		memset(visited, 0, sizeof(visited));
		int mid = (high + low) / 2;
		if (dfs(from, mid))
		{
			if (ans < mid)
				ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans;
	
}

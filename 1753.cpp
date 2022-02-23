#include <bits/stdc++.h>

using namespace std;

typedef int vertex;
typedef int weight;
const int INF = 987654321;
int start;
vector<pair<vertex, weight>> graph[20001];
int dist[20001];

void shortest_path(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		auto newEdge = pq.top();
		int newStart = newEdge.second;
		int newDist = newEdge.first;
		pq.pop();
		if(newDist > dist[newStart])
			continue;
		for (auto edge : graph[newStart])
		{
			int nextvertex = edge.first;
			int nextdist = edge.second + newDist;
			if (dist[nextvertex] < nextdist)
				continue;
			dist[nextvertex] = nextdist;
			pq.push(make_pair(nextdist, nextvertex));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	cin >> start;
	for (int i = 1; i <= V; ++i)
	{
		dist[i] = INF;
	}
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	shortest_path(start);
	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INF)
			cout << "INF";
		else 
			cout << dist[i];
		cout << '\n';
	}
}
#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<int> graph[1001];
void dfs(int v) {
	bool visited[1001]{ 0 };
	stack<int> s;
	int startNode = v;
	visited[v] = true;
	cout << v<<" ";
	for (int i = 1; i <= 1000; ++i) {
		sort(graph[i].begin(), graph[i].end(), greater<>());
	}
	for (auto nodeV : graph[v]) {
		s.push(nodeV);
	}
	while (!s.empty()) {
		int next = s.top();
		s.pop();
		if (visited[next])
			continue;
		cout << next << " ";
		visited[next] = true;
		for (auto nodeNext : graph[next]) {
			s.push(nodeNext);
		}
	}
	cout << '\n';
}

void bfs(int v) {
	int visited[1001]{ 0 };
	queue<int> q;
	int startNode = v;
	visited[v] = true;
	cout << v << " ";
	for (int i = 1; i <= 1000; ++i) {
		sort(graph[i].begin(), graph[i].end());
	}
	for (auto nodeV : graph[v]) {
		q.push(nodeV);
	}
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		if (visited[next])
			continue;
		cout << next << " ";
		visited[next] = true;
		for (auto nodeNext : graph[next]) {
			q.push(nodeNext);
		}
	}
	cout << '\n';

}

int main() {
	int n, m,v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i) {
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	
	dfs(v);
	bfs(v);

}
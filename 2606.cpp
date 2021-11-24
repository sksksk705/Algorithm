#include <bits/stdc++.h>

using namespace std;

vector<int> network[101];
bool visited[101];

void bfs(int i) {
	if (visited[i] == true)
		return;
#ifndef ONLINE_JUDGE
	cout << i << " ";
#endif // !ONLINE_JUDGE
	visited[i] = true;
	for (auto a : network[i]) {
		int next = network[i].back();
		network[i].pop_back();
		bfs(next);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	int w;
	cin >> w;

	for (int i = 0; i < w; ++i) {
		int node1, node2;
		cin >> node1 >> node2;

		network[node1].push_back(node2);
		network[node2].push_back(node1);
	}

	bfs(1);

	int sum = 0;
	for (int i = 2; i <= n; ++i) {
		sum += visited[i];
	}
	cout << sum;
}
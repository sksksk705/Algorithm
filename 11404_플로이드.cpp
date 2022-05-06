//2022_05_04 그래프
//11404 플로이드

//플로이드 와샬 알고리즘

#include <bits/stdc++.h>

using namespace std;

int graph[101][101];
const int MAX = 987654321;

int main() {
	int n,m;
	cin >> n>>m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			graph[i][j] = MAX;
		}

	for (int i = 1; i <= m; ++i) {
		int a, b,w;
		cin >> a >> b>>w;
		graph[a][b] =min(graph[a][b],w);
	}

	for(int k = 1; k <= n;++k)
		for(int i = 1 ; i <= n;++i)
			for (int j = 1; j <= n; ++j) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << (graph[i][j] == MAX ? 0 : graph[i][j]) << " ";
		}
		cout << '\n';
	}
}
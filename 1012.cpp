#include <bits/stdc++.h>

using namespace std;

int Map[51][51];
bool visited[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x,int y,int& worm) {
	++worm;
	queue<int> xq;
	queue<int> yq;
	visited[x][y] = true;
	xq.push(x);
	yq.push(y);
	while (!xq.empty()) {
		int nowx = xq.front();
		int nowy = yq.front();
		xq.pop();
		yq.pop();
		for (int i = 0; i < 4; ++i) {
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];
			if (Map[nextx][nexty] == 1 && !visited[nextx][nexty]
				&& nextx >= 0 && nextx <= 50
				&& nexty >= 0 && nexty <= 50) {
				xq.push(nextx);
				yq.push(nexty);
				visited[nextx][nexty] = true;
			}
		}
	}


}

int main() {
	int t;
	cin >> t;
	for (int _ = 0; _ < t; ++_) {
		int worm = 0;
		int m, n, k;
		cin >> m >> n >> k;
		for (int i = 0; i < k; ++i) {
			int x, y;
			cin >> x >> y;
			Map[x][y] = 1;
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (Map[i][j] == 1 && !visited[i][j]) {
					bfs(i, j, worm);
				}
			}
		}
		cout << worm<<'\n';
		memset(visited, 0, 51 * 51 * sizeof(bool));
		memset(Map, 0, 51 * 51 * sizeof(int));
	}
	return 0;
}
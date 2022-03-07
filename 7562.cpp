#include <bits/stdc++.h>

using namespace std;
const int MAX = 987654321;
int dx[8]{ 1,2,2,1,-1,-2,-2,-1 };
int dy[8]{ -2,-1,1,2,2,1,-1,-2 };
bool visited[300][300];
int dist[300][300];
int n;
void bfs(int startx, int starty, int tox, int toy) {
	queue<pair<int, int>> posq;
	queue<int> moveq;
	visited[starty][startx] = true;
	posq.push(make_pair(startx, starty));
	moveq.push(0);
	while (!posq.empty()) {
		auto nowpos = posq.front();
		int nowdist = moveq.front();
		posq.pop();
		moveq.pop();
		for (int i = 0; i < 8; ++i) {
			int nextx = nowpos.first + dx[i];
			int nexty = nowpos.second + dy[i];
			if (nextx < 0 || nextx >= n ||
				nexty < 0 || nexty >= n ||
				visited[nexty][nextx])
				continue;
			visited[nexty][nextx] = true;
			dist[nexty][nextx] = nowdist+1;
			posq.push(make_pair(nextx, nexty));
			moveq.push(nowdist + 1);
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		int startx, starty;
		cin >> startx >> starty;
		int tox, toy;
		cin >> tox >> toy;
		bfs(startx, starty, tox, toy);
		cout << dist[toy][tox]<<'\n';
	}
}
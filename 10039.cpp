#include <bits/stdc++.h>

using namespace std;

int maze[101][101];
bool visited[101][101];
int depth[101][101];
int dx[4]{ 0,0,-1,1 };
int dy[4]{ 1,-1,0,0 };
void bfs() {
	int move = 0;
	queue<pair<int,int>> q;
	int startx = 1;
	int starty = 1;
	visited[startx][starty] = true;
	depth[startx][starty] = 1;
	q.push(make_pair(startx, starty));
	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];
			if (!visited[nextx][nexty] && maze[nextx][nexty] == 1) {
				visited[nextx][nexty] = true;
				q.push(make_pair(nextx, nexty));
				depth[nextx][nexty] = depth[nowx][nowy]+1;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			maze[i][j] = s[j - 1] - '0';
		}
	}
	bfs();
	cout << depth[n][m];
}
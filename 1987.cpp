#include <bits/stdc++.h>

using namespace std;
int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
int MAP[20][20];
bool visited[20][20];
bool passAlpha[26];
int r, c;

int dfs(int x, int y) {
	int ret = 1;
	for (int i = 0; i < 4; ++i) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (nextx >= 0 && nextx < c &&
			nexty >= 0 && nexty < r &&
			!visited[nexty][nextx] &&
			!passAlpha[MAP[nexty][nextx]]) {
			visited[nexty][nextx] = true;
			passAlpha[MAP[nexty][nextx]] = true;
			ret = max(ret, dfs(nextx, nexty)+1);
			visited[nexty][nextx] = false;
			passAlpha[MAP[nexty][nextx]] = false;
		}
	}
	return ret;
}

int main() {

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			char c;
			cin >> c;
			MAP[i][j] = c - 'A';
		}
	visited[0][0] = true;
	passAlpha[MAP[0][0]] = true;
	cout<<dfs(0, 0);
}
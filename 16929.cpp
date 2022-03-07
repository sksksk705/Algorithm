#include <bits/stdc++.h>

using namespace std;
int n, m;
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
int startx, starty;
char startcolor;
bool visited[50][50];
char board[50][50];

bool haveCycle(int nowx,int nowy, int depth) {
	for (int i = 0; i < 4; ++i) {
		int nextx = nowx + dx[i];
		int nexty = nowy + dy[i];
		if (depth > 2 && nextx == startx && nexty == starty)
			return true;
		if (nextx < 0 || nextx >= m ||
			nexty < 0 || nexty >= n||
			visited[nexty][nextx] || board[nexty][nextx]!= startcolor)
			continue;
		visited[nexty][nextx] = true;
		if (haveCycle(nextx, nexty, depth + 1))
			return true;
		visited[nexty][nextx] = false;
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	bool result = false;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			starty = i;
			startx = j;
			startcolor = board[i][j];
			visited[i][j] = true;
			if (haveCycle(startx, starty, 0)) {
				result = true;
				break;
			}
		}
	if (result)
		cout << "Yes";
	else
		cout << "No";
}
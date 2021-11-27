#include <bits/stdc++.h>

using namespace std;

clock_t start, finish;
double duration;

int box[1001][1001];
bool visited[1001][1001];
int depth[1001][1001];
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
int m, n;
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];

			if (nextx<0 || nextx > n ||
				nexty<0 || nexty > m)
				continue;
			if (!visited[nextx][nexty] && box[nextx][nexty] == 0) {
				visited[nextx][nexty] = true;
				if (depth[nextx][nexty] <= depth[nowx][nowy])
					continue;
				depth[nextx][nexty] = depth[nowx][nowy] + 1;
				q.push({ nextx,nexty });
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		memset(visited[i], 0, sizeof(int) * m);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			depth[i][j] = INT_MAX;
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int tomato;
			cin >> tomato;
			if (tomato == -1|| tomato == 1)
				depth[i][j] = 0;
			box[i][j] = tomato;
			if (tomato == 1) {
				q.push({ i,j });
			}
		}
	}
	
	bfs();

	priority_queue<int> sort_queue;
	for (int i = 0; i < n; ++i) {
		sort_queue.push(*max_element(depth[i], depth[i] + m));
	}
	int result = sort_queue.top();


	if (result == INT_MAX)
		cout << "-1";
	else
		cout << result;
}
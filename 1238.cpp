#include <bits/stdc++.h>

using namespace std;
int MAX = 987654321;

list<pair<int,int>> town[1001];
int dp[1001][1001];
int n, m, x;

void bfs(int from, int to) {
	if (dp[from][to] != MAX)
		return;
	queue<int> q;
	queue<int> timeq;
	q.push(from);
	timeq.push(0);
 	while (!q.empty()) {
		int now = q.front();
		int time = timeq.front();
		q.pop(); timeq.pop();
		for (auto t : town[now])
		{
			int next = t.first;
			int nexttime = time + t.second;
			if (nexttime >= dp[from][next])
				continue;
			dp[from][next] = nexttime;
			q.push(next);
			timeq.push(nexttime);
		}
	}

}

int main() {

	cin >> n >> m >> x;
	for (int i = 0; i < m; ++i) {
		int from, to, time;
		cin >> from >> to >> time;
		town[from].push_back(make_pair(to,time));
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dp[i][j] = MAX;
	int result = 0;
	dp[x][x] = 0;
	for (int i = 1; i <= n; ++i)
	{
		bfs(i, x);
		bfs(x, i);
		result = max(result, dp[i][x] + dp[x][i]);
	}
	cout << result;
}
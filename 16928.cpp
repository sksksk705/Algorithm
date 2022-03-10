#include <bits/stdc++.h>

using namespace std;
int laddernSnake[101];
bool visited[101];

int bfs(int start, int end) {
	queue<int> q;
	queue<int>moveq;
	q.push(start);
	moveq.push(0);
	while (!q.empty()) {
		int now = q.front();
		int move = moveq.front();
		q.pop(); moveq.pop();
		for (int i = 1; i <= 6; ++i) {
			int next = now + i;
			if (visited[next])
				continue;
			visited[next] = true;
			if (next >= 100)
				return move + 1;
			if (laddernSnake[next]) {
				next = laddernSnake[next];
				visited[next] = true;
			}
			q.push(next);
			moveq.push(move + 1);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+m; ++i) {
		int from, to;
		cin >> from >> to;
		laddernSnake[from] = to;
	}
	cout<<bfs(1, 100);
}
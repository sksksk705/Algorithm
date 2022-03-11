#include <bits/stdc++.h>

using namespace std;

const int MAX = 200002;
int possible[3]{ -1,1};
bool visited[200002];

int bfs(int start, int to) {
	queue<int> q;
	queue<int> moveq;
	moveq.push(0);
	q.push(start);
	while (!q.empty()) {
		auto now = q.front();
		int move = moveq.front();
		if (now == to)
			return move;
		q.pop(); moveq.pop();
		int next = 2 * now;
		while (next <= MAX && next != 0) {
			if (next < 0 || next >= MAX ||
				visited[next]) {
				next *= 2;
				continue;
			}
			visited[next] = true;
			q.push(next);
			moveq.push(move);
			next *= 2;
		}
		for (int i = 0; i < 2; ++i) {
			next = now + possible[i];
			if (next < 0 || next >= MAX ||
				visited[next])
				continue;
			visited[next] = true;
			q.push(next);
			moveq.push(move+1);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	if (n >= k) {
		cout << n - k;
	}
	else
		cout<<bfs(n, k);

}
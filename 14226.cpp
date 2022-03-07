#include <bits/stdc++.h>

using namespace std;

bool visited[1501][1501];
const int MAX = 1501;
 int bfs(int s, int goal) {
	queue<int> q;
	queue<int> clipq;
	queue<int> timeq;
	q.push(s);
	clipq.push(0);
	timeq.push(0);
	while (!q.empty()) {
		int now = q.front();
		int nowclip = clipq.front();
		int nowtime = timeq.front();
		q.pop(); clipq.pop(); timeq.pop();
		for (int i = 0; i < 3; ++i) {
			int next;
			int nextclip;
			switch (i)
			{
			case 0:
				next = now;
				nextclip = now;
				break;
			case 1:
				next = now + nowclip;
				nextclip = nowclip;
				break;
			case 2:
				next = now - 1;
				nextclip = nowclip;
			}
			if (next < 0 || next >= MAX||visited[next][nextclip])
				continue;
			if (next == goal) {
				return nowtime + 1;
			}
			visited[next][nextclip] = true;
			timeq.push(nowtime + 1);
			clipq.push(nextclip);
			q.push(next);
		}
	}
	return 0;
}

int main() {
	int s;
	cin >> s;
	cout<<bfs(1,s);
}
#include <bits/stdc++.h>
#include <string>

using namespace std;

int Map[25][25];
bool visited[25][25];
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
int n;
int bfs(int i, int j) {
	int result = 1;
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y =q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (!visited[nextx][nexty] && Map[nextx][nexty]&&
				nextx >= 0 && nextx <= 24 &&  //범위체크를 하지 않으면 케이스 통과가 안 됨.
				nexty >= 0 && nexty <= 24) {
				q.push(make_pair(nextx,nexty));
				visited[nextx][nexty] = true;
				++result;
			}
		}
	}
	return result;
}


int main() {
	priority_queue<int, vector<int>, greater<int>> danji;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string house;
		cin >> house;
		for (int j = 0; j < n; ++j) {
			Map[i][j] = house[j] - '0';
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (Map[i][j] == 0 || visited[i][j])
				continue;
			else {
				int ans = bfs(i, j);
				danji.push(ans);
			}
		}
	}

	cout << danji.size()<<'\n';
	while (!danji.empty()) {
		cout << danji.top() << "\n";
		danji.pop();
	}
}
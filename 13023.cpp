#include <bits/stdc++.h>

using namespace std;

list<int> isFriend[2000];		//친구 관계가 2000개 이기 때문에 링크드리스트가 더 효과적
bool visited[2000];
int n,m;

bool dfs(int a, int depth) {
	if (depth > 4)
		return true;
	for (auto next : isFriend[a]) {
		if (visited[next])
			continue;
		visited[next] = true;
		if (dfs(next, depth + 1))
			return true;
		visited[next] = false;
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		isFriend[a].push_back(b);
		isFriend[b].push_back(a);
	}
	bool haveABCDE = false;
	for (int i = 0; i < n; ++i) {
		if (dfs(i, 0)) {
			haveABCDE = true;
			break;
		}
	}
	cout << haveABCDE;
}
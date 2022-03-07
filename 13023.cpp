#include <bits/stdc++.h>

using namespace std;

list<int> isFriend[2000];		//ģ�� ���谡 2000�� �̱� ������ ��ũ�帮��Ʈ�� �� ȿ����
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
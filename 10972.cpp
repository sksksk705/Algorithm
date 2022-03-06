#include <bits/stdc++.h>

using namespace std;
int n;
int seq[10001];
vector<int> result;
bool shouldPrint;
bool visited[10001];
bool solution(int idx) {
	if (shouldPrint && idx == n) {
		for (auto i : result) {
			cout << i << " ";
		}
		return true;
	}
	if (idx == n) {
		shouldPrint = true;
		return false;
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i])
			continue;
		if (i == seq[idx]|| shouldPrint) {
			visited[i] = true;
			result.push_back(i);
			if (solution(idx + 1))
				return true;
			result.pop_back();
			visited[i] = false;
		}
	}
	return false;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
	}
	if (!solution(0))
		cout << -1;
}
#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
vector<int> result;
bool visited[8];
int n, m;

void makeSeq(int idx, int num) {
	if (num == m) {
		for (auto i : result) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	for (int i = idx+1; i < n; ++i) {
		if (visited[i])
			continue;
		result.push_back(vec[i]);
		visited[i] = true;
		makeSeq(i, num + 1);
		visited[i] = false;
		result.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	makeSeq(-1, 0);
	return 0;
}

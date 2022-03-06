#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
set<int> s;
vector<int> result;
int n, m;

void makeSeq(int idx, int num) {
	if (num == m) {
		for (auto i : result) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < vec.size(); ++i) {
		if (idx == -1 || vec[i] >= result.back()) {
			result.push_back(vec[i]);
			makeSeq(i, num + 1);
			result.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		s.emplace(num);
	}
	for (auto i : s)
		vec.push_back(i);
	sort(vec.begin(), vec.end());
	makeSeq(-1, 0);
	return 0;
}

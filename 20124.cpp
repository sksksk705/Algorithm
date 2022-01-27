#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string, int> m1, pair<string, int>m2) {
	if (m1.second == m2.second)
		return m1 < m2;
	return m1.second > m2.second;
}
int main() {
	int n;
	cin >> n;
	vector<pair<string, int>> v;
	for (int i = 0; i < n; ++i) {
		string name;
		int score;

		cin >> name >> score;

		v.push_back({ name, score });
	}

	sort(v.begin(), v.end(), cmp);

	cout << v.front().first;
}
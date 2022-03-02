#include <bits/stdc++.h>
using namespace std;

int n, m;
int paper;
int high;
int low;
set<int> col_set;
vector<int> col_vec;

void input() {
	cin >> n >> m;
	high = max(n,m);
	cin >> paper;
	int wrong;
	cin >> wrong;
	while (wrong--) {
		int x, y;
		cin >> y >> x;
		col_set.emplace(x);
		if (low < y)
			low = y;
	}
	
}

int solution() {
	if (col_set.size() <= paper)
		return low;
	for (auto x : col_set)
		col_vec.push_back(x);
	int ans = 1000001;
	while (low <= high) {
		int idx = 0;
		int mid = (low + high) /2;
		for (int i = 1; i <= paper; ++i) {
			if (idx == col_vec.size())
				break;
			int now = col_vec[idx];
			while (idx < col_vec.size() && now + mid > col_vec[idx]) {
				idx++;
			}
		}
		if (idx == col_vec.size()) {
			high = mid - 1;
			if (ans > mid)
				ans = mid;
		}
		else
			low = mid + 1;
	}
	return ans;
}

int main() {
	input();
	cout << solution();
}
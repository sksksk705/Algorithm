#include <bits/stdc++.h>

using namespace std;

void Change(vector<string>& a, int row, int col) {
	for (int i = row; i < row + 3; ++i) {
		for (int j = col; j < col + 3; ++j) {
			if (a[i][j] == '0')
				a[i][j] = '1';
			else
				a[i][j] = '0';
		}
	}
}

int main() {
	vector<string> a;
	vector<string> b;
	string buf;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> buf;
		a.push_back(buf);
	}

	for (int i = 0; i < n; ++i) {
		cin >> buf;
		b.push_back(buf);
	}



	int cnt = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m - 2; ++j) {
			if (a[i][j] != b[i][j]) {
				Change(a, i, j);
				cnt += 1;
			}
		}
	}

	if (a != b)
		cout << -1;
	else
		cout << cnt;

}
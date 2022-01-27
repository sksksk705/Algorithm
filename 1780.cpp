#include <bits/stdc++.h>

using namespace std;

int paper_num[3];
int paper[2187][2187];
void cutpaper(int x, int y,int size) {
	int num = paper[x][y];
	if (size == 1) {
		++paper_num[num + 1];
		return;
	}

	try {
		for (int i = x; i < x + size; ++i) {
			for (int j = y; j < y + size; ++j) {
				if (paper[i][j] != num)
					throw new exception();
			}
		}
		++paper_num[num + 1];
	}
	catch (...) {
		for (int i = x; i < x + size; i += size / 3) {
			for (int j = y; j < y + size; j += size / 3) {
				cutpaper(i, j, size / 3);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			paper[i][j] = num;
		}
	}

	cutpaper(0, 0, n);

	for (auto a : paper_num)
		cout << a<<'\n';

}
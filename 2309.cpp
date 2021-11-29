#include <bits/stdc++.h>

using namespace std;

int hobit[9];
int main() {
	vector<int> sorting;
	for (int i = 0; i < 9; ++i) {
		int height;
		cin >> height;
		hobit[i] = height;
	}

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (j == i)
				continue;
			int result = 0;
			for (int k = 0; k < 9; ++k) {
				if (k == i || k == j)
					continue;
				result += hobit[k];
			}
			if (result == 100) {
				for (int k = 0; k < 9; ++k) {
					if (k == i || k == j)
						continue;
					sorting.push_back(hobit[k]);
				}
				sort(sorting.begin(), sorting.end());

				for (auto a : sorting) {
					cout << a << '\n';
				}
				return 0;
			}
		}
	}

	
}
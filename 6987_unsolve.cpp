#include <iostream>

using namespace std;

int comp[4][18];
int league;

bool can() {
	for (int i = 0; i < 18; ++i)
		if (comp[league][i])
			return false;
	return true;
}
bool checkresult(int p) {
	if (can())
		return true;
	for (int i = p; i < 18; ++i) {
		if (comp[league][i] > 0)
		{
			int idx = i / 3;
			int result = 2 - i % 3;
			for (int j = 0; j < 6; ++j) {
				if (idx == j || comp[league][j * 3 + result] == 0) continue;
				if (j == 5 && comp[league][i] > comp[league][j * 3 + result]) return false;
				comp[league][i]--;
				comp[league][j * 3 + result]--;
				if (checkresult(i))
					return true;
				comp[league][i]++;
				comp[league][j * 3 + result]++;
			}
		}
		if (comp[league][i] > 0)
			return false;
	}
	return false;
}

int main() {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 18; ++j)
			cin >> comp[i][j];

	for (int i = 0; i < 4; ++i) {
		league = i;
		bool possible = true;
		for (int j = 0; j < 6; ++j) {
			int sum = 0;
			for (int k = 0; k < 3; ++k) {
				sum += comp[league][j * 3 + k];
			}
			if (sum != 5) {
				possible = false;
				break;
			}
		}
		if (!possible) {
			cout << 0 << " ";
			continue;
		}
		if (checkresult(0))
			cout << 1;
		else
			cout << 0;
		cout << " ";

	}
}
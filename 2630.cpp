#include <bits/stdc++.h>

using namespace std;

const int WHITE = 0;
const int BLUE = 1;
short paper[128][128];
int blue_paper;
int white_paper;

bool check_same_color(int x, int y, int n) {
	short color = paper[x][y];
	for (int i = x; i < x + n; ++i) {
		for (int j = y; j < y + n; ++j) {
			if (paper[i][j] != color)
				return false;
		}
	}
	return true;
}

void cut_paper(int x, int y, int n) {
	short color = paper[x][y];
	if (n == 1) {
		if (color == WHITE)
			white_paper++;
		else if (color == BLUE)
			blue_paper++;
		return;
	}

	if (check_same_color(x, y, n)) {
		if (color == WHITE)
			white_paper++;
		else if (color == BLUE)
			blue_paper++;
		return;
	}

	cut_paper(x, y, n / 2);
	cut_paper(x+n/2, y, n / 2);
	cut_paper(x, y + n / 2, n / 2);
	cut_paper(x + n / 2, y + n / 2, n / 2);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> paper[i][j];
		}
	}

	cut_paper(0, 0, n);

	cout << white_paper << endl;
	cout << blue_paper << endl;
}
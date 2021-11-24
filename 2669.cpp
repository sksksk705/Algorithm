#include <iostream>

using namespace std;

int squares[4][4];
int Map[101][101];
int main() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int x;
			cin >> x;
			squares[i][j] = x;
		}
	}

	int result = 0;
	for (int i = 0; i < 4; ++i) {
		int left = squares[i][0];
		int right = squares[i][2];
		int bottom = squares[i][1];
		int top = squares[i][3];
		for (int j = left; j < right; ++j) {
			for (int k = bottom; k < top; ++k) {
				Map[j][k] = 1;
			}
		}
	}

	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			result += Map[i][j];
		}
	}

	cout << result;

}
#include <bits/stdc++.h>

using namespace std;

int zero[41];
int one[41];

int main() {
	zero[0] = 1;
	zero[1] = 0;

	one[0] = 0;
	one[1] = 1;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		for (int j = 2; j <= n; j++) {
			if (!zero[j]) {
				zero[j] = zero[j - 1] + zero[j - 2];
				one[j] = one[j - 1] + one[j - 2];
			}
		}
		cout << zero[n] << " " << one[n] << '\n';
	}
}
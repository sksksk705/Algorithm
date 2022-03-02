#include <bits/stdc++.h>

using namespace std;
int n, m;

int possible[41];

int main() {
	cin >> n >> m;

	possible[1] = 1;
	possible[2] = 2;
	for (int i = 3; i <= 40; ++i) {
		possible[i] = possible[i - 1] + possible[i-2];
	}
	int result = 1;
	int prev = 1;
	for (int i = 0; i < m; ++i) {
		int vip;
		cin >> vip;
		if (vip != prev)
			result *= possible[vip - prev];
		prev = vip+1;
	}
	if (n + 1 != prev)
		result *= possible[n + 1 - prev];
	cout << result;
	return 0;
}
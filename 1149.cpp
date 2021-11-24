#include <bits/stdc++.h>

using namespace std;

int dp[3][1001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int r, g, b;
		cin >> r>> g>> b;
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + r;
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + g;
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + b;
	}

	cout << min(min(dp[0][n], dp[1][n]), dp[2][n]);
}
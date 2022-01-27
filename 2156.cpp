#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int bar[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int wine;
		cin >> wine;
		bar[i] = wine;
	}

	dp[0] = 0;
	dp[1] = bar[1];
	dp[2] = bar[1] + bar[2];
	for (int i = 3; i <= n; ++i) {
		dp[i] = max(max(dp[i - 3] + bar[i - 1] + bar[i], dp[i - 2] + bar[i]), dp[i - 1]);
	}

	cout << dp[n];
}
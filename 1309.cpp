#include <bits/stdc++.h>

using namespace std;

int dp[100001][3];
const int MOD = 9901;
int main() {
	int n;
	cin >> n;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][0] = 1;

	for (int i = 2; i <= n; ++i) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
		dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
	}
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		sum += dp[n][i];
	}
	cout << sum%9901;
}
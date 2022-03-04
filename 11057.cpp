#include <bits/stdc++.h>

using namespace std;
int dp[1000][10];
int main() {
	for (int i = 0; i < 10; ++i) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 1000; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= j; ++k) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k])%10007;
			}
		}
	}
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans = (ans + dp[n][i]) % 10007;
	}
	cout << ans;
}
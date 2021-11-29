#include <iostream>

using namespace std;

long long dp[101];
int main() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	int t;
	cin >> t;
	for (int _ = 0; _ < t; ++_) {
		int n;
		cin >> n;

		for (int i = 6; i <= n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}

		cout << dp[n]<<'\n';
	}
}
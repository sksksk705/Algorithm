#include <iostream>

using namespace std;

int n;
int dp[31];

int main() {
	cin >> n;
	dp[2] = 3;
	dp[4] = 11;
	for (int i = 3; i <= n / 2; ++i) {
		dp[i * 2] = dp[(i - 1) * 2]*3;
		if (i % 2 == 0) {
			dp[i * 2] += dp[(i - 2) * 2] * 2;
		}
	}
	cout << dp[n];
}
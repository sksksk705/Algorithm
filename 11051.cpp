#include <iostream>

using namespace std;

int dp[1002][1002];
int main() {
	int n, k;
	cin >> n >> k;

	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] =(dp[i-1][j-1] + dp[i-1][j])% 10007;
		}
	}

	cout << dp[n][k];
}
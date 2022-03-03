#include <iostream>
using namespace std;

long long dp[100001][4];
const int MOD = 1000000009;
int main() {
	int T;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i <= 100000; ++i){
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		long long sum = 0;
		for (int i = 1; i < 4; ++i) {
			sum += dp[n][i];
		}
		cout << sum % MOD<<'\n';
	}
}
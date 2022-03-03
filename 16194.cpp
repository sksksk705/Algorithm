#include <iostream>

using namespace std;

int dp[1001];
int card[1001];
const int MAX = 987654321;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		dp[i] = MAX;
		cin >> card[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] = min(dp[i], card[i - j] + dp[j]);
		}
	}
	cout << dp[n];
}
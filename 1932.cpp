#include <bits/stdc++.h>

using namespace std;

int dp[502][502];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			int num;
			cin >> num;
			dp[i][j] = num + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	
	if (n == 1)
		cout << dp[1][1];
	else
		cout << *max_element(dp[n], dp[n] + n+1);
	
}
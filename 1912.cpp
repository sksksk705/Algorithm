#include <bits/stdc++.h>

using namespace std;


vector<int> v;
int dp[100001];
int main() {
	int n;
	cin >> n;
	int result = 0;
	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		dp[i] = num;
	}
	int max_sum = -1001;
	int num = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = max(dp[i], dp[i - 1] + dp[i]);
	}
	

	cout << *max_element(dp+1,dp+n+1);
}
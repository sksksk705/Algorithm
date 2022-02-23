#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int price[1001];
int n;

void mostExpansiveWay()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			dp[i] = max(dp[i], dp[i - j] + price[j]);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> price[i];
	}
	mostExpansiveWay();
	cout << dp[n];
}
#include <iostream>

using namespace std;

int dp[1000001];

int main()
{
	int n;
	cin >> n;
	int i = 3;
	dp[1] = 1;
	dp[2] = 2;
	while (i <= n)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
		i++;

	}
	cout << dp[n];
}
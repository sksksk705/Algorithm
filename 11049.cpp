#include <iostream>
using namespace std;

long long dp[501][501];
long long matrix[501][2];			//0세로 1가로
long long mul[501][501];
const int INF = 987654321;
int main()
{
	int n;
	cin >> n;
	mul[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> matrix[i][0] >> matrix[i][1];
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; i + j <= n; ++j)
		{
			dp[j][i+j] = INF;
			for (int k = j; k <= i + j; ++k)
			{
				dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k + 1][i + j]+matrix[j][0] * matrix[k][1]* matrix[i+j][1]);
			}
		}
	}
	cout << dp[1][n];
}
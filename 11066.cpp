#include <iostream>
#include <cstring>
using namespace std;

int dp[501][501];
int sum[501];
int file[501];
int T, K;
const int INF = 987654321;
int main()
{
	cin >> T;
	for (int _ = 0; _ < T; ++_)
	{
		memset(dp, 0, sizeof(dp));
		cin >> K;
		for (int i = 1; i <= K; ++i)
		{
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}

		for (int i = 1; i <= K; ++i)
		{
			for (int j = 1; j <= K - i; ++j)
			{
				dp[j][i + j] = INF;
				for (int k = j; k < i + j; ++k)
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k+1][i+j] + sum[i + j] - sum[j-1]);
			}
		}
		cout << dp[1][K]<<'\n';
	}

}
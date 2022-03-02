#include <iostream>
using namespace std;

int sum[50001];
int train[50001];
int dp[50001][3];
int t,c;

int solution(int idx, int train) {
	if (idx > t || train == 3) return 0;
	int& ret = dp[idx][train];
	if (ret != 0) return ret;
	if (idx + c - 1 <= t) {
		ret = max(solution(idx + 1, train), solution(idx + c, train + 1) + sum[idx + c - 1] - sum[idx - 1]);
	}
	return ret;
}

int main()
{

	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cin >> train[i];
		sum[i] = sum[i - 1] + train[i];
	}
	cin >> c;
	int result = solution(1, 0);
	cout << result;
}
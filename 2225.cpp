#include <iostream>

using namespace std;

int dp[201][201];
int N;
int K;
int result = 0;
int plusSep(int _n, int _k)
{
	int& ret = dp[_n][_k];
	if (ret != 0)
		return ret;
	if (_n == N)
		return 1;
	if (_k == K)
		return 0;
	for (int i = 0; i <= N; ++i)
	{
		if (_n + i <= N) {
			ret += plusSep(_n + i, _k + 1);
		}
		ret %= 1000000000;
	}
	return ret;
}

int main()
{
	cin >> N >> K;
	int result = plusSep(0, 0);
	cout << result;
}
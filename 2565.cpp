#include <bits/stdc++.h>

using namespace std;

int dp[501];
int line[501];
int checkline(int start)
{
	if (line[start] == 0) return -1;				//전깃줄이 없는 라인은 구하지 않음.
	int& ret = dp[start];
	if (ret != 0) return ret;
	ret = 1;
	for (int next = start +1; next < 501; ++next)	//모든 경우의 수를 구할 수 밖에 없음.
	{
		if (line[next] > line[start] || start == 0)
		{
			ret = max(ret, checkline(next) + 1);	//모든 라인에 대해 증가수열을 구함
		}
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	line[0] = 501;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		line[a] = b;
	}
	int result = n - checkline(0) + 1;				//0번이 스스로를 포함하기 때문에 결과에 1을 더해줌
	cout << result;
}
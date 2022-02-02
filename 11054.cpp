#include <bits/stdc++.h>

using namespace std;

int n;
int num_list[1001];
int lis_dp[1001];
int lds_dp[1001];


int lds(int lds_start) {								 //가장 긴 감소수열을 찾는 함수
	int& ret = lds_dp[lds_start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = lds_start + 1; next <= n; ++next)
	{
		if (num_list[lds_start] > num_list[next]) {
			ret = max(ret, lds(next) + 1);
		}
	}
	return ret;
}

int lis(int lis_end) {									 //가장 긴 증가수열을 찾는 함수
	int& ret = lis_dp[lis_end];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = lis_end -1; next >= 1; --next)
	{
		if (num_list[lis_end] > num_list[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num_list[i];
	}
	memset(lis_dp, -1, sizeof(lis_dp));
	memset(lds_dp, -1, sizeof(lds_dp));
	int max_val = 0;
	for (int i = 1; i <= n; ++i)
	{
		lis(i);
		lds(i);
		max_val = max(max_val, lis_dp[i] + lds_dp[i] - 1);
	}

	cout << max_val;
}
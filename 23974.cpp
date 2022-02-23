#include <bits/stdc++.h>

using namespace std;

int dp[10000000][2];

bool evengame(int n,int k){
	bool ygisnoteven = n % 2;
	int& ret = dp[k][ygisnoteven];
	if (ret != -1) return ret;
	if (!ygisnoteven && k == 1)
		return false;
	if (ygisnoteven && k == 0)
		return false;
	for (int i = 1; i < 5; ++i)
	{
		if (k - i < 0)
			continue;
		if (evengame(n + i, k - i))
			ret = true;
	}
	return ret;
}

int main()
{
	int n, k;
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));
	bool ygwin = evengame(n, k);
	if (ygwin)
		cout << "YG";
	else
		cout << "HS";
 }
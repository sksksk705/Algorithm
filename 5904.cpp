#include <bits/stdc++.h>

using namespace std;

int dp[28];
int find_n_in_moo(int n, int k,int start)
{
	int ret = -1;
	if (n > start + dp[k-1] && n < start + dp[k-1] + k + 3) {
		return n - start - dp[k-1];
	}
	else if (n < start + dp[k - 1])
		ret = find_n_in_moo(n, k - 1, start);
	else
		ret = find_n_in_moo(n, k - 1, start + dp[k - 1]+ k +2);

	return ret;
		

}
int main()
{
	int n;
	cin >> n;
	int k = 1;
	int moo = 3;
	while (moo < n)
	{
		dp[k] = moo;
		moo = moo * 2 + (k + 3);
		k++;
	}
 	cout << (find_n_in_moo(n,k,0) == 1 ? "m" : "o");
}
#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];
string fst;
string snd;
int lcs(int fst_sub_idx, int snd_sub_idx)
{
	if (fst_sub_idx == fst.size() || snd_sub_idx == snd.size())
		return 0;
	int& ret = dp[fst_sub_idx][snd_sub_idx];
	if (ret != -1) return ret;
	ret = 0;
	if (fst[fst_sub_idx] == snd[snd_sub_idx])
		ret = lcs(fst_sub_idx + 1, snd_sub_idx + 1) + 1;
	else
		ret = max(lcs(fst_sub_idx + 1, snd_sub_idx), lcs(fst_sub_idx, snd_sub_idx + 1));
	return ret;
}

int main()
{
	cin >> fst >> snd;
	memset(dp,-1,sizeof(dp));
	int LCS = lcs(0, 0);
	cout << LCS;
}
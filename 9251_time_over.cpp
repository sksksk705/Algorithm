#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];
int lcs(string fst, string snd, int fst_sub_idx, int snd_sub_idx)
{
	if (snd == "") return 0;
	int& ret = dp[fst_sub_idx][snd_sub_idx];
	if (ret != -1) return ret;
	ret = 0;
	for (auto fst_idx = fst_sub_idx; fst_idx < fst.size(); ++fst_idx)
	{
		int idx = snd.find(fst[fst_idx]);
		if(idx != string::npos)
		{
			ret = max(ret, (lcs(fst, snd.substr(idx+1), fst_idx + 1, snd_sub_idx+idx+1) + 1));
		}
	}
	return ret;
}

int main()
{
	string fst, snd;
	cin >> fst >> snd;
	memset(dp,-1,sizeof(dp));
	int LCS = lcs(fst, snd, 0, 0);
	cout << LCS;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int ret;
vector<int> coin_vec;
int dp[10001];
void comb(int moneyNeeded, int usedCoin)
{
	if (moneyNeeded == 0) {
		ret++;
		return;
	}
	if (usedCoin + 1 >= coin_vec.size())
		return;
	int nowCoin = coin_vec[usedCoin + 1];
	for (int i = moneyNeeded / nowCoin; i >= 0; --i)
	{
		comb(moneyNeeded - nowCoin * i, usedCoin + 1);
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int coin;
		cin >> coin;
		coin_vec.push_back(coin);
	}
	sort(coin_vec.begin(), coin_vec.end(), greater<int>());
	comb(k, -1);
	cout << ret;
}
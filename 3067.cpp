//2022_03_28 동적계획법 경우의 수
//3067 Coins

//돈은 1~10000원까지, 동전은 20 종류 배열 크기 가능
//정답
#include <bits/stdc++.h>

using namespace std;

int cache[20][10001];
int coins[20];
int n;

int makeMoney(int idx, int money) {
	if (idx == n) {
		if (money == 0)
			return 1;
		return 0;
	}
	int& ret = cache[idx][money];
	if (ret != -1)
		return ret;
	ret = 0;
	int amount = money / coins[idx];
	for (int i = 0; i <= amount; ++i) {
		ret += makeMoney(idx + 1, money - coins[idx] * i);
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> coins[i];
		int m;
		cin >> m;
		cout << makeMoney(0, m)<<'\n';
	}
	return 0;
}
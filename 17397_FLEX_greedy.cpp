//2022_04_11 랜덤문제풀이
//17397번 FLEX

#include <bits/stdc++.h>

using namespace std;

int n, m;
const int INF = 987654321;;
int cache[1001][201];
int payment[1000];


int flex(int days, int currentMoney) {
	//기저사례: 모든 날이 지나갔다.
	if (days == n)
		return 0;

	int& ret = cache[days][currentMoney];

	int dis = payment[days - 1] - payment[days];
	if(dis<= 0)
		ret = min(ret, flex(days + 1, currentMoney));
	else {
		for (int pay = dis; pay >= 0; --pay) {
			if (pay <= currentMoney) {
				payment[days] += pay;
				ret = min(ret, flex(days + 1, currentMoney - pay) + (int)pow(dis - pay, 2));
				payment[days] -= pay;
			}
		}
	}


	return ret;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> payment[i];
	}
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			cache[i][j] = INF;
}

int solve(){
	if (n == 1)
		return 0;
	return flex(0,m);
}

int main() {
	input();
	int result = solve();
	cout << result;
}
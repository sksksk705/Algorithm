//2022_04_11 랜덤문제풀이
//17397번 FLEX

#include <bits/stdc++.h>

using namespace std;

int n, m;
const int INF = 987654321;;
int payment[1000];
int noMoneyDay[1001];
int best;

int caculation(int day) {
	int ret = 0;
	for (int i = day; i < n; ++i) {
		if (payment[i] < payment[i - 1])
			ret += pow(payment[i] - payment[i - 1], 2);
		noMoneyDay[i] = ret;
	}
	return ret;
}


//currentValue: 지금까지의 박탈감
//days: 오늘 날짜
//currentMoney: 남은 금액
void flex(int currentValue, int days, int currentMoney) {
	//휴리스틱
	if (currentValue >= best)
		return;

	//기저사례1: 마지막날까지 지났음.
	if (days == n) {
		best = min(currentValue, best);
		return;
	}

	//전날과 당일의 차이
	int dis = payment[days - 1] - payment[days];

	//기저사례2: 더이상 돈이 없다.
	if (currentMoney == 0)
	{
		//현재값 + 오늘의 박탈감 + 내일부터의 박탈감
		best = min(currentValue + (int)pow(dis, 2) + noMoneyDay[days+1], best);
		return;
	}
	else
	{
		//전날이 오늘보다 높을 때에만 돈을 사용한다.
		//최고는 전날과 같아 질 수 있는 금액부터 0원까지 사용
		if (dis > 0)
		{
			for (int pay = dis; pay >= 0; --pay) {
				if (pay > currentMoney)
					continue;
				payment[days] += pay;
				flex(currentValue + pow(dis - pay, 2), days + 1, currentMoney - pay);
				payment[days] -= pay;
			}
		}
		else
			flex(currentValue, days + 1, currentMoney);
	}
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> payment[i];
	}
}

int solve(){
	if (n == 1)
		return 0;
	best = caculation(1);
	for (int i = n - 1; i > 0; --i) {
		noMoneyDay[i] = best - noMoneyDay[i - 1];
	}
	flex(0,1,m);
	return best;
}

int main() {
	input();
	int result = solve();
	cout << result;
}
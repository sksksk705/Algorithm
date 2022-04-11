//2022_04_11 ��������Ǯ��
//17397�� FLEX

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


//currentValue: ���ݱ����� ��Ż��
//days: ���� ��¥
//currentMoney: ���� �ݾ�
void flex(int currentValue, int days, int currentMoney) {
	//�޸���ƽ
	if (currentValue >= best)
		return;

	//�������1: ������������ ������.
	if (days == n) {
		best = min(currentValue, best);
		return;
	}

	//������ ������ ����
	int dis = payment[days - 1] - payment[days];

	//�������2: ���̻� ���� ����.
	if (currentMoney == 0)
	{
		//���簪 + ������ ��Ż�� + ���Ϻ����� ��Ż��
		best = min(currentValue + (int)pow(dis, 2) + noMoneyDay[days+1], best);
		return;
	}
	else
	{
		//������ ���ú��� ���� ������ ���� ����Ѵ�.
		//�ְ�� ������ ���� �� �� �ִ� �ݾ׺��� 0������ ���
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
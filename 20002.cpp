//2022_03_24 ��������Ǯ��
//20002 �������

//21:27�� ����
//x,y��ġ���� k��ŭ�� ���簢���� ���� y -> y + k����ŭ (x + k �� ��) - (x������ ��)
//22:04 ���� ����üũ�ϴ°� ������� y�� 1���� x�� 0����, x + k�� n����, y + k�� n+1����
#include <bits/stdc++.h>

using namespace std;

const int NEGINF = INT_MIN;
int sum[302][302];
int n;

int calculate(int y, int x, int workSize)
{
	int result = 0;
	for (int i = y; i < y + workSize; ++i)
	{
		result += (sum[i][x + workSize] - sum[i][x]);
	}
	return result;
}

int getBestProfit()
{
 	int ret = NEGINF;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 1; k + j <= n && k + i <= n+1; ++k)
			{
				ret = max(ret, calculate(i, j, k));
			}
		}
	}
	return ret;
}

int main() {

	cin >> n;
	for(int i = 1 ; i <= n;++i)
		for (int j = 1; j <= n; ++j) {
			int profit;
			cin >> profit;
			sum[i][j] = sum[i][j - 1] + profit;
		}

	int bestProfit = getBestProfit();
	cout << bestProfit;
}
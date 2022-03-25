//2022_03_24 랜덤문제풀이
//20002 사과나무

//21:27분 시작
//x,y위치에서 k만큼의 정사각형의 값은 y -> y + k열만큼 (x + k 의 합) - (x까지의 합)
//22:04 정답 범위체크하는게 힘들었음 y는 1부터 x는 0부터, x + k는 n까지, y + k는 n+1까지
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
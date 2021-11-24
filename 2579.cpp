#include <bits/stdc++.h>

using namespace std;

int dp[3][301]; //누적합 테이블
int stairs[301]; //계단 점수 테이블
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int score;
		cin >> score;
		stairs[i] = score;
	}
	dp[1][1] = stairs[1];
	for (int i = 2; i <= n; ++i) {
		dp[1][i] = max(dp[2][i - 2],dp[1][i-2]) + stairs[i]; //처음 밟는 건 2단계전 1번 밟은 것이거나 2번 밟은 것의 점수와 현재 계단 점수의 합.
		dp[2][i] = dp[1][i - 1] + stairs[i]; //2번째 밟는 건 그전 계단의 점수에 현재 계단의 점수를 추가.
	}

	cout << max(dp[1][n], dp[2][n]); //무조건 밟아야하기 때문에 밟은 단계의 점수.
}
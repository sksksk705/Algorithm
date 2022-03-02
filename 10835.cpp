#include <bits/stdc++.h>

using namespace std;

int dp[2001][2001];
int cardL[2001];
int cardR[2001];
int n;

int solution(int left, int right) {
	if (left > n - 1 || right > n - 1)
		return 0;
	int& ret = dp[left][right];
	if (ret != -1)
		return ret;
	if (cardL[left] > cardR[right])
	{
		ret = max(ret, solution(left, right+1) + cardR[right]);
	}
	else {
		ret = max(ret, solution(left+1, right));
		ret = max(ret, solution(left+1, right + 1));
	}
	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cardL[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> cardR[i];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dp[i][j] = -1;
	cout << solution(0, 0);
}
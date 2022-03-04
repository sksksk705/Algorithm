#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int num[1001];
int n;
int solution(int prev, int idx) { 
	int& ret = dp[idx+1];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = idx+1; i < n; ++i) {
		if (idx == -1 || num[i] > prev)
		{
			ret = max(dp[idx+1], solution(num[i], i) + num[i]);
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		dp[i] = -1;
	}
	cout << solution(-1, -1);
}
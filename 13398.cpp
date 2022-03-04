#include <bits/stdc++.h>

using namespace std;

int dp[100002][2];
int num[100002];
int n;
const int MIN = -100000001;

int solution(int idx, bool del) {
	if (idx + 1 > n - 1)
		return 0;
	int& ret = dp[idx+1][del];
	if (ret != MIN)
		return ret;
	if (idx == -1) {
		for (int i = idx + 1; i < n; ++i) {
			ret = max(num[i], max(ret,solution(i, del)+num[i]));
		}
	}
	else {
		ret = num[idx + 1];
		if (del) {
			ret = max(ret, solution(idx + 1, del) + num[idx+1]);
		}
		else {
			ret = max(ret ,solution(idx + 1, 0) + num[idx+1]);
			ret = max(ret, solution(idx + 1, 1));
		}

	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = MIN;
		}
	}
	cout << solution(-1, false);
}
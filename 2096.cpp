#include <bits/stdc++.h>

using namespace std;

int dp[2][2][3]; //dp[최대,최소][현재,다음][왼,중,오]
int main() {
	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < 3; ++i) {
		int a;
		cin >> a;
		dp[0][0][i] = a;
		dp[1][0][i] = a;
	}

	for (int i = 1; i < n; ++i) {
		cin >> a >> b >> c;
		int maxleft, maxright, maxmid;
		int minleft, minright, minmid;

		maxleft = dp[0][(i - 1) % 2][0];
		maxmid = dp[0][(i - 1) % 2][1];
		maxright = dp[0][(i - 1) % 2][2];

		minleft = dp[1][(i - 1) % 2][0];
		minmid = dp[1][(i - 1) % 2][1];
		minright = dp[1][(i - 1) % 2][2];

		dp[0][i % 2][0] = a + max(maxleft, maxmid);
		dp[0][i % 2][1] = b + max(max(maxleft, maxmid),maxright);
		dp[0][i % 2][2] = c + max(maxright, maxmid);
		
		dp[1][i % 2][0] = a + min(minleft, minmid);
		dp[1][i % 2][1] = b + min(min(minleft, minmid), minright);
		dp[1][i % 2][2] = c + min(minright, minmid);

		
	}

	cout << *max_element(dp[0][(n - 1)%2], dp[0][(n - 1) % 2] + 3)<<" " << *min_element(dp[1][(n - 1) % 2], dp[1][(n - 1) % 2] + 3) << endl;
}


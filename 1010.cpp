#include <iostream>

using namespace std;

int n;
int m;

int dp[31][31];
int make_bridge(int west, int east)
{
	int& ret = dp[west][east];
	if (ret != 0)
		return ret;
	if (west == 0)
		return ++ret;
	int next_west = west - 1;
	for (int next_east = east - 1; next_east >= next_west; next_east--) {
		ret += make_bridge(next_west, next_east);
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		int ret = make_bridge(n,m);
		cout << ret<<'\n';
	}
}
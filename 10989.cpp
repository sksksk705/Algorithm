#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	vector<int> idx;
	for (int i = 0; i < n; ++i) {
		int elem;
		cin >> elem;
		++dp[elem];
	}

	for (int i = 1; i < 10001; ++i) {
		for (int j = dp[i]; j > 0; --j) {
			cout << i << '\n';
		}
	}

}
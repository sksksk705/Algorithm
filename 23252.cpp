#include <iostream>

using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (c > a) {
			cout << "No\n";
			continue;
		}

		if (a != 0 && b % 2 == 1) b--;

		if ((a - c) % 2 == 0 && b % 2 == 0) cout << "Yes\n";
		else cout << "No\n";
	}
}
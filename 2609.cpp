#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int big = max(n, m);
	int small = min(n, m);

	for (int i = big; i > 0; --i) {
		if (small % i == 0 && big % i == 0) {
			cout << i<<'\n';
			break;
		}
	}

	for (int i = big; i <= n * m; ++i) {
		if (i % big == 0 && i % small == 0) {
			cout << i << '\n';
			break;
		}
	}
}
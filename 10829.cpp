#include <bits/stdc++.h>

using namespace std;

void tenTotwo(long long n) {
	if (n == 0)
		return;
	else {
		tenTotwo(n / 2);
		cout << n % 2;
	}
}

int main() {
	long long n;
	cin >> n;
	tenTotwo(n);

	return 0;
}
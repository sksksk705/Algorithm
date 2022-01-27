#include <bits/stdc++.h>

using namespace std;

int have[1000001];
int need[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int lesson;
		cin >> lesson;
		++have[lesson];
	}

	for (int i = 1; i <= n; ++i) {
		int lesson;
		cin >> lesson;
		++need[lesson];
	}

 	for (int i = 1; i <= 1000000; ++i) {
		while (true) {
			if (have[i] && need[i]) {
				--have[i];
				--need[i];
			}
			else
				break;
		}
	}

	for (int i = 1; i <= 1000000; ++i) {
		have[i] += have[i - 1];
	}

	cout << have[1000000];
}
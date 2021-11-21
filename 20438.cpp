#include <bits/stdc++.h>

using namespace std;

int student[5003];
bool sleep[5003];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);


	int n, k, q, m;

	int stu;

	cin >> n >> k >> q >> m;

	for (int i = 0; i < k; ++i) {
		cin >> stu;
		sleep[stu] = true;
	}
	for (int i = 3; i <= n + 2; ++i) {
		student[i] = 1;
	}
	for (int i = 0; i < q; ++i) {
		cin >> stu;
		if (sleep[stu])
			continue;
		int num = stu;
		while (true) {
			if (num > n+2)
				break;
			if (!sleep[num])
				student[num] = 0;
			num += stu;
		}
	}
	int s, e;
	for (int i = 4; i <= n + 2; ++i) {
		student[i] += student[i - 1];
	}
	for (int i = 0; i < m; ++i) {
		cin >> s >> e;
		cout << student[e] - student[s-1] << '\n';
	}
}
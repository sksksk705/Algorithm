#include <bits/stdc++.h>

using namespace std;
int n;
int op[4];
int num[12];
long long MAX = -1000000001;
long long MIN = 1000000001;

void solution(int idx, int result) {
	if (idx > n-1) {
		if (result > MAX)
			MAX = result;
		if (result < MIN)
			MIN = result;
		return;
	}
	for (int j = 0; j < 4; ++j) {
		if (op[j] > 0) {
			op[j]--;
			switch (j)
			{
			case 0:
				solution(idx+1, result + num[idx]);
				break;
			case 1:
				solution(idx + 1, result - num[idx]);
				break;
			case 2:
				solution(idx + 1, result * num[idx]);
				break;
			case 3:
				solution(idx + 1, result / num[idx]);
				break;
			}
			op[j]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> op[i];
	}
	solution(1, num[0]);
	cout << MAX <<'\n' << MIN;
}
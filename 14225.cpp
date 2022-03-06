#include <bits/stdc++.h>

using namespace std;

bool canMake[2000001];
int num[20];
int n;

void solution(int idx, int result) {
	canMake[result] = true;
	if (idx > n-1)
		return;
	for (int i = idx + 1; i < n; ++i) {
		solution(i, result + num[i]);
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	solution(-1, 0);
	int idx = 0;
	while (canMake[idx])
	{
		idx++;
	}
	cout << idx;

}
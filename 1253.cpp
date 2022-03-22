#include <bits/stdc++.h>
#include <unordered_map>
//메모리 초과 (앞에 것을 다시 탐색하지 않는 것으로 해결
//0 10 3 같은 자신을 더하는 것에서 오류 발생 2022_03_18
using namespace std;
int n;
vector<int> a;
unordered_map<int, int> hashtable;
int result = 0;

void bruteforce(int idx, int sum, int elem) {
	if (elem == 2) {
		result += hashtable[sum];
		hashtable[sum] = 0;
		return;
	}
	for (int i = idx+1; i < n; ++i) {
		if (idx == -1)
		{
			bruteforce(i, a[i], 1);
		}
		else {
			bruteforce(i, sum + a[i], elem + 1);
		}
	}
	return;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int Ai;
		cin >> Ai;
		hashtable[Ai]++;
		a.push_back(Ai);
	}
	sort(a.begin(), a.end());
	bruteforce(-1,0,0);
	cout << result;
}
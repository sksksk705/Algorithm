#include <bits/stdc++.h>
#include <unordered_map>
//메모리 초과
using namespace std;
int n;
vector<int> a;
unordered_map<int, int> hashtable;

void bruteforce(int idx, int sum) {
	for (int i = idx + 1; i < n; ++i) {
		if (idx != -1) {
			hashtable[a[i] + sum]++;
		}
		if (a[i] + sum > a.back())
			continue;
		bruteforce(i,a[i] + sum);
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int Ai;
		cin >> Ai;
		a.push_back(Ai);
	}
	sort(a.begin(), a.end());
	bruteforce(-1,0);

	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (hashtable[a[i]])
			result++;
	}
	cout << result;
}
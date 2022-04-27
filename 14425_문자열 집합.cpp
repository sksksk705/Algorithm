//2022_04_25 문자열
//14425번 문자열 집합

//해시쓰면 풀리는 문제.
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unordered_set<string> dic;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		dic.emplace(str);
	}

	int ret = 0;
	for (int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		if (dic.find(str) != dic.end())
			ret++;
	}

	cout << ret;
}
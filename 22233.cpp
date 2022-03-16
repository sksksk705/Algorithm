#include <bits/stdc++.h>
#include <unordered_set>
#include <sstream>

using namespace std;
unordered_set<string> memo;//1번만 등장하기에 map대신 set을 사용

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string keyword;
		cin >> keyword;
		memo.insert(keyword);
	}
	int result = n;
	for (int i = 0; i < m; ++i) {
		string writing;
		cin >> writing;
		stringstream sin(writing);
		string used_key;
		while (getline(sin, used_key, ',')) {
			if (memo.find(used_key)!=memo.end())
			{
				memo.erase(used_key);
				result--;
			}
		}
		cout << result<<'\n';
	}
	return 0;
}
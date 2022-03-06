#include <bits/stdc++.h>

using namespace std;
int n;
int k;
int ans = 0;
string must = "acint";
set<char> wordNeed[51];
bool learnedC[26];


void solution(int alpha, int learned) {
	if (learned > k-1) {
		int canRead = n;
		for (int i = 0; i < n; ++i) {
			for (auto c : wordNeed[i]) {
				if (!learnedC[c - 'a']) {		//필요한 단어를 배우지 못했다면 빼기
					canRead--;
					break;
				}
			}
		}
		if (canRead > ans)
			ans = canRead;
		return;
	}
	for (int i = alpha + 1; i <= 'z'-'a'; ++i) {
		if (must.find(i+'a') != string::npos)
			continue;			
		learnedC[i] = true;			//비트마스크 활용
		solution(i, learned + 1);
		learnedC[i] = false;
	}
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j) {
			if (must.find(s[j]) != string::npos)
				continue;
			wordNeed[i].emplace(s[j]);
		}
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	solution(0, 5);
	cout << ans;

}
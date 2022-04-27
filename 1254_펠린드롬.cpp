//2022_04_25 문자열
//1254번_팰린드롬

//공부했던 KMP알고리즘으로 가장 많이 겹치는 구간을 찾고 해당 문자열을 2배한 길이에서 뺴주면 답
#include <bits/stdc++.h>

using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int n = N.size();
	vector<int> pi(n, 0);

	int begin = 1, matched = 0;
	while (begin + matched < n) {
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int kmpSearch(const string& H, const string N) {
	int n = H.size();
	vector<int> pi = getPartialMatch(N);
	int ret = 0;
	int matched = 0;
	for (int i = 0; i < n; ++i)
	{
		while (matched > 0 && H[i] != N[matched]) 
			matched = pi[matched - 1];
		if (H[i] == N[matched]) 
			++matched;
		
	}
	return matched;
}

int main() {
	string s;
	cin >> s;
	string sprime = s;
	reverse(sprime.begin(), sprime.end());
	
	int ret = kmpSearch(s, sprime);
	cout << s.size() * 2 - ret;
}
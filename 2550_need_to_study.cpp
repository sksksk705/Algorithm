#include <bits/stdc++.h>

using namespace std;

int swit[10001];
int light[10001];
int choice[10001];
int dp[10001];
int n; 
int solution(int idx) {
	int& ret = dp[idx+1];
	if (ret != -1)
		return ret;
	ret = 1;
	int bestNext = -1;
	for (int i = idx + 1; i < n; ++i) {
		if (idx == -1 || light[swit[idx]] < light[swit[i]]) {
			int cand = solution(i) + 1;
			if (cand > ret) {
				ret = cand;
				bestNext = i;
			}
		}
	}
	choice[idx + 1] = bestNext;
	return ret;
}

void reconstruct(int start, vector<int>& seq) {
	if (start != -1) seq.push_back(swit[start]);
	int next = choice[start + 1];
	if (next != -1) reconstruct(next, seq);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> swit[i];
		dp[i] = -1;
		choice[i] = -1;
	}
	dp[n] = -1;
	for (int i = 1; i <= n; ++i) {
		int s;
		cin >> s;
		light[s] = i;
	}
	solution(-1);
	vector<int> result;
	reconstruct(-1, result);
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (auto r : result)
		cout << r << " ";
}
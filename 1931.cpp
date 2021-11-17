#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}


int main() {
	vector<pair<int, int>> meetings;

	int N, start, end;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> start >> end;
		meetings.push_back(make_pair(start, end));
	}

	sort(meetings.begin(), meetings.end(), cmp);

	int now = 0;
	int ans = 1;
	for (int i = 1; i < N ; ++i) {
		if (meetings[now].second <= meetings[i].first) {
			now = i;
			ans += 1; 
		}
	}
	cout << ans;
}
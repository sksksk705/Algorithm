#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


vector<pair<int, int>> gems;
int n, k;
vector<int> bag;
priority_queue<int> pq;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int m, v;
		cin >> m >> v;
		gems.emplace_back(make_pair(m, v));
	}
	for (int i = 0; i < k; ++i)
	{
		int b;
		cin >> b;
		bag.emplace_back(b);
	}
	sort(bag.begin(), bag.end());
	sort(gems.begin(), gems.end());
	long long result = 0;
	int idx = 0;
	for (int i = 0; i < k; ++i)
	{
		while (idx < n && bag[i] >= gems[idx].first) {
			pq.push(gems[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
long long n, l, p;
vector<pair<int, int>> station;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long a, b;
		cin >> a >> b;
		station.push_back(make_pair(a,b));
	}
	sort(station.begin(), station.end());
	cin >> l >> p;
	priority_queue<int> pq;
	int idx = 0;
	int result = 0;
	while (p < l)
	{
		while (idx < n && station[idx].first <= p)
		{
			pq.push(station[idx].second);
			idx++;
		}
		if (!pq.empty())
		{
			p += pq.top();
			result++;
			pq.pop();
		}
		else {
			result = -1;
			break;
		}
	}
	cout << result;
}
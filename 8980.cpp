#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, c,m;
vector<pair<int, int>> village[2001];
int truck[2001];
int main()
{
	cin >> n >> c >> m;
	for (int i = 0; i < m; ++i)
	{
		int from, to, box;
		cin >> from >> to >> box;
		village[from].push_back(make_pair(to, box));
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(village[i].begin(), village[i].end());
	}
	int town = 1;
	int ans = 0;
	while (town <= n)
	{
		int idx = 0;
		c += truck[town];
		ans += truck[town];
		truck[town] = 0;
		while (idx < village[town].size())
		{
			int to = village[town][idx].first;
			int box = village[town][idx].second;
			truck[to] += box;
			c -= box;
			idx++;
		}
		if (c < 0) {
			for (int i = n; i > 0; --i)
			{
				if (c + truck[i] < 0)
				{
					c += truck[i];
					truck[i] = 0;
				}
				else if (c + truck[i] >= 0)
				{
					truck[i] += c;
					c = 0;
					break;
				}
			}
		}
		town++;
	}
	cout << ans;
}
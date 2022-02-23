#include <bits/stdc++.h>

using namespace std;

int getSign[500001];
int main()
{
	int n;
	cin >> n;
	stack<pair<int,int>> towers;
	for (int i = 1; i <= n; ++i)
	{
		int tower_height;
		cin >> tower_height;
		towers.push(make_pair(i, tower_height));
	}
	stack<pair<int, int>> no_sign;
	while (!towers.empty())
	{
		auto nexttower = towers.top();
		towers.pop();
		if (!no_sign.empty()) {
			while (no_sign.top().second < nexttower.second)
			{
				getSign[no_sign.top().first] = nexttower.first;
				no_sign.pop();
				if (no_sign.empty())
					break;
			}
		}
		no_sign.push(nexttower);
	}
	while (!no_sign.empty())
	{
		auto not_accepted_tower = no_sign.top();
		no_sign.pop();
		getSign[not_accepted_tower.first] = 0;
	}
	for (int i = 1; i <= n;++i)
	{
		cout << getSign[i] << ' ';
	}
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<int, int> table;
	
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int card;
		cin >> card;
		auto exist_card = table.find(card);
		if (exist_card != table.end())
		{
			++(exist_card->second);
		}
		else
			table.emplace(card, 1);
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int card;
		cin >> card;
		auto exist_card = table.find(card);
		if (exist_card == table.end())
			cout << 0 << " ";
		else
			cout << exist_card->second<<' ';
	}

}
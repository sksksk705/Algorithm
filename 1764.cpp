#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int result = 0;
	map<string, int>  unknown;
	for (int i = 0; i < n; ++i)
	{
		string people;
		cin >> people;
		unknown.emplace(people,1);
	}
	for (int i = 0; i < m; ++i)
	{
		string people;
		cin >> people;
		auto it = unknown.find(people);
		if (it != unknown.end()) {
			it->second++;
			result++;
		}
	}
	cout << result<<'\n';
	for (auto people : unknown)
	{
		if(people.second > 1)
		cout << people.first << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;

map<string, int> alpha;
map<int, string> numbering;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		string pokemon;
		cin >> pokemon;
		alpha.emplace(pokemon, i);
		numbering.emplace(i, pokemon);
	}

	for (int i = 0; i < m; ++i)
	{
		string problem;
		cin >> problem;
		if (isalpha(problem[0]))
			cout << alpha.find(problem)->second;
		else
			cout << numbering.find(stoi(problem))->second;
		cout << '\n';
	}
}
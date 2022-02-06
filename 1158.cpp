#include <bits/stdc++.h>

using namespace std;

//배열로 풀기
/* 
bool visited[5001];
set<int> s;
int main() {
	int n, k;
	cin >> n >> k;

	int start = 0;
	cout << "<";
	while (true) {
		for (int i = 0; i < k; ++i) {
			if (visited[++start%n])
				--i;
		}
		start %= n;

		if (start == 0)
			cout << n;
		else
			cout << start;

		s.emplace(start);
		visited[start] = true;
		if(s.size() == n)
			break;
		cout << ", ";
	}
	cout << ">";
}
 */

//리스트로 풀기
#include <list>

void yosepus(list<int> table, int k)
{
	cout << "<";
	auto it = table.begin();
	while (table.size() != 1) {
		for (int i = 0; i < k-1; ++i)
		{
			if (it == table.end())
				it = table.begin();
			it++;
		}
		if (it == table.end())
			it = table.begin();
		cout << *it<<", ";
		it = table.erase(it);
	}
	cout << table.back() << ">";
}

int main()
{
	int n, k;
	cin >> n >> k;
	list<int> table;
	for (int i = 1; i <= n; ++i)
	{
		table.emplace_back(i);
	}
	yosepus(table, k);
	return 0;
}
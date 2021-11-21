#include <bits/stdc++.h>

using namespace std;


int main() {
	int n, k;

	cin >> n >> k;
	int people  = 0;
	list<int> table;

	for (int i = 1; i <= n; ++i) {
		table.push_back(i);
	}
	cout << "<";
	auto it = table.begin();
	while (true) {
		for (int i = 1; i < k;++i) {
			++it;
			if (it == table.end())
				it = table.begin();
		}
		cout << *it;
		it = table.erase(it);
		if (it == table.end())
			it = table.begin();
		if (table.empty())
			break;
		cout << ", ";
	}
	cout << ">";
}
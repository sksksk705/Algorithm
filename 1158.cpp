#include <bits/stdc++.h>

using namespace std;

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
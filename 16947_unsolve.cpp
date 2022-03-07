#include <bits/stdc++.h>

using namespace std;
list<int> subway[3001];
bool visited[3001];
int circuit_station;
bool makecircuit(int station) {
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int from, to;
		cin >> from >> to;
		subway[from].push_back(to);
		subway[to].push_back(from);
	}

	makecircuit(1);
}
#include <bits/stdc++.h>

using namespace std;

int a[1000000];
int b[1000000];
int ans[2000000];
int main() {
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pq.emplace(a);
	}

	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		pq.emplace(a);
	}

	while (!pq.empty()) {
		cout << pq.top()<<" ";
		pq.pop();
	}
	*/

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i){	
		int num;
		cin >> num;
		a[i] = num;
	}
	
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		b[i] = num;
	}

	int pa = 0;
	int pb = 0;

	for (int i = 0; i < n + m; ++i) {
		if (a[pa] <= b[pb] && pa != n || pb == m)
			ans[i] = a[pa++];
		else
			ans[i] = b[pb++];
	}

	for (int i = 0; i < n + m; ++i) {
		cout << ans[i] << " ";
;}
}
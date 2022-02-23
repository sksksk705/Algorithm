#include <iostream>
#include <vector>

using namespace std;
vector<int> parents(1000001);

void make_set(int x) {
	parents[x] = x;
	return;
}

int do_find(int x) {
	if (x == parents[x]) return x;
	return parents[x] = do_find(parents[x]);
}

void do_union(int u, int v) {
	u = do_find(u);
	v = do_find(v);
	if (u == v) return;
	parents[u] = v;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n>>m;
	for (int i = 0; i <= n; ++i)
	{
		make_set(i);
	}
	for (int i = 0; i < m; ++i)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0)
			do_union(a, b);
		if (op == 1) {
			a = do_find(a);
			b = do_find(b);
			if (a == b)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
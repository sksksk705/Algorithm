#include <bits/stdc++.h>

using namespace std;
vector<int> sequence;
void seq(int n, int m, int now_num)
{
	if (sequence.size() == m)
	{
		for (auto elem : sequence)
			cout << elem << " ";
		cout << "\n";
	}
	for (int next = now_num + 1; next <= n; ++next)
	{
		sequence.push_back(next);
		seq(n, m, next);
		sequence.pop_back();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	seq(n, m, 0);
}
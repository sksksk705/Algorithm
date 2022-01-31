#include <bits/stdc++.h>

using namespace std;

bool taken[9];

void make_perm(vector<int>& perm, int perm_size)
{
	if (perm.size() == perm_size)
	{
		for (auto elem : perm)
			cout << elem << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= perm_size; ++i)
	{
		if (taken[i]) continue;
		perm.push_back(i);
		taken[i] = true;
		make_perm(perm, perm_size);
		perm.pop_back();
		taken[i] = false;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> perm;
	make_perm(perm, n);
}
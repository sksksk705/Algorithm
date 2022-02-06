#include <bits/stdc++.h>

using namespace std;

vector<int> result;
int n;
int m;
void seq(int now)
{
	if (result.size() == m)
	{
		for (auto elem : result)
			cout << elem << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		result.push_back(i);
		seq(i);
		result.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	
	seq(0);
}
#include <bits/stdc++.h>

using namespace std;

vector<int> result;
int n;
int m;

bool is_dec()
{
	if (result.size() == 1)
		return false;
	for (int i = 0; i < result.size()-1; ++i)
	{
		if (result[i] > result[i + 1])
			return true;
	}
	return false;
}
void seq(int now)
{
	if (result.size() == m)
	{
		if (!is_dec()) {
			for (auto elem : result)
				cout << elem << " ";
			cout << "\n";
			return;
		}
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
#include <bits/stdc++.h>

using namespace std;


int lotto[13];
int n;
vector<int> final_choice;

void print_lotto()
{
	for (auto elem : final_choice)
	{
		cout << elem << " ";
	}
	cout << '\n';
}

void make_lotto(int idx, int remain)
{
	
	if (final_choice.size() == 6)
	{
		print_lotto();
		return;
	}
	for (int i = idx+1; i < n; ++i)
	{
		if (i + remain-1 >= n)
			continue;
		final_choice.push_back(lotto[i]);
		make_lotto(i, remain - 1);
		final_choice.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	cin >> n;
	while (n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> lotto[i];
		}
		make_lotto(-1, 6);
		cout << '\n';
		cin >> n;
	}
}
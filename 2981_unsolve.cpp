#include <bits/stdc++.h>

using namespace std;

int arr[100];
int n;

bool is_mod(int mod, int num)
{
	for (int i = 0 ; i <n;++i)
	{
		if (arr[i] % num != mod) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int my_min = 1000000001;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int elem;
		cin >> elem;
		if (elem < my_min)
			my_min = elem;
		arr[i] = elem;
	}
	for (int i = 2; i < my_min; ++i)
	{
		int mod = my_min % i;
		if (is_mod(mod, i))
			cout << i << " ";
	}
}
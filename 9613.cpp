#include <iostream>
#define FASTIO		ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int testnum[101];

int getGCD(int n, int m)
{
	int big = max(n, m);
	int small = min(n, m);
	int gcd = small;
	while (big % small != 0)
	{
		gcd = big % small;
		big = small;
		small = gcd;
	}
	return gcd;
}

int main()
{
	FASTIO
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> testnum[i];
		}
		long long result = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				result += getGCD(testnum[i], testnum[j]);
			}
		}
		cout << result<<'\n';
	}
	return 0;
}
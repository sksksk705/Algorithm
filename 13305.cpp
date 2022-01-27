#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	valarray<long long> dist(n - 1);
	for (int i = 0; i < n-1; ++i)
	{
		cin >> dist[i];
	}
	valarray<long long> price(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}
	valarray<long long> result(n);
	int min = INT_MAX;
	for (int i = 0; i < n-1; ++i)
	{
		if (price[i] < min)
			min = price[i];
		result[i] = min * dist[i];
	}

	cout << result.sum();

	return 0;
}
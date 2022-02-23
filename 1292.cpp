#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long result = 0;
	int n;
	cin >> n;
	if (n <  10) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= 9; ++i)
	{
		long long full = i * (pow(10, i) - pow(10, i - 1));
		if (n / pow(10, i) >= 1)
		{
			result += full;
			continue;
		}
		result += i * (n - int(pow(10, i - 1))+1);
		break;
	}
	cout << result;
}
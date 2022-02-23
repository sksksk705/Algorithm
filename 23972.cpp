#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k, n;
	cin >> k >> n;
	if (n == 1) {
		cout<<-1;
		return 0;
	}
	long long imoney = k * n / (n - 1);
	if (k * n % (n-1) != 0)
		imoney++;
	cout << imoney;
}
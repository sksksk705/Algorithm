#include <iostream>

long long  dp[46];
long long fibonacci(int n)
{
	long long& ret = dp[n];
	if (ret != 0) return ret;
	if (n == 0) ret = 0;
	else if (n == 1) ret = 1;
	else ret = fibonacci(n - 1) + fibonacci(n - 2);
	return ret;
}

int main()
{
	using std::cout;
	using std::cin;

	int n;
	cin >> n;
	long long result = fibonacci(n);
	cout << result;
}
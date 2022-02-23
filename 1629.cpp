#include <iostream>

using namespace std;

long long multi(long long a, long long b, long long c)
{
	long long ret = 0;
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	long long b1, b2;
	long long half = multi(a, b / 2, c);
	if (b % 2 == 0) ret = half * half % c;
	else			ret = half * (half * a % c) % c;
	return ret;
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;

	long long result = multi(a%c, b, c);
	cout << result;
}
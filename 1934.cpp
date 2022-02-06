#include <iostream>

using namespace std;

long long lcm(int a, int b)
{
	long long result = 1;

	while (true)
	{
		int lcd = -1;
		for (int i = 2; i <= min(a, b); ++i)
		{
			if ( a%i == 0 &&  b%i == 0) {
				lcd = i;
				break;
			}
		}
		if (lcd == -1)
			break;
		a /= lcd;
		b /= lcd;
		result *= lcd;
	}
	result = result * a * b;
	return result;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << lcm(a, b)<<'\n';
	}
}
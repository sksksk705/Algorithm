#include <iostream>

using namespace std;

int cnt;

int main()
{
	int n;
	cin >> n;
	if (n < 5) {
		cout << "0";
		return 0;
	}
	int fact = 24;
	for (int i = 5; i <= n; ++i)
	{
		fact *= i;
		while (fact % 10 == 0 && fact / 10 > 0)
		{
			fact /= 10;
			cnt++;
		}
		fact %= 1000;
	}
	cout << cnt;
	return 0;
}
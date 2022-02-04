#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int result = 0;
	for (int i = 0; i < 5; ++i)
	{
		int serial;
		cin >> serial;
		result += pow(serial, 2);
	}
	cout << result % 10;
}
#include <iostream>

using namespace std;

int pipe[65];
int main()
{
	int X;
	cin >> X;
	pipe[64] = 1;
	int result = 0;
	while (true)
	{
		int shortest = 65;
		int full_length = 0;
		for (int i = 1; i <= 64; ++i)
		{
			if (pipe[i] > 0) {
				shortest = min(i, shortest);
				full_length += i * pipe[i];
			}
		}
		if (full_length > X)
		{
			pipe[shortest]--;
			pipe[shortest / 2] +=  2;
			if (full_length - shortest / 2 >= X)
			{
				pipe[shortest / 2] -= 1;
				full_length -= shortest / 2;
			}
		}
		if (full_length == X)
		{
			for (int i = 1; i <= 64; ++i)
			{
				result += pipe[i];
			}
			break;
		}
	}
	cout << result;
}
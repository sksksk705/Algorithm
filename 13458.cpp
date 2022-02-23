#include <iostream>
using namespace std;

int N;
int B, C;
long long result = 0;
int test[1000000];
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> test[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; ++i)
	{
		result++;
		if (test[i] - B <= 0)
			continue;
		result += (test[i] - B) / C + ((test[i] - B) % C != 0);
	}
	cout << result;
}
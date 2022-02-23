#include <iostream>

using namespace std;

int numArr[1001];
int n;
int k;
int mininarr()
{
	for (int i = 2; i <= n; ++i)
	{
		if (numArr[i])
			return i;
	}
	return -1;
}

int main()
{
	cin >> n>>k;

	for (int i = 2; i <= n; ++i)
	{
		numArr[i] = true;
	}
	int result = 0;
	int mini = mininarr();
	while (mini != -1)
	{
		numArr[mini] = false;
		result++;
		if (result == k) {
			cout << mini;
			break;
		}
		for (int i = mini+1; i <= n; ++i)
		{
			if (i % mini == 0 && numArr[i]) {
				numArr[i] = false;
				result++;
				if (result == k) {
					cout << i;
					break;
				}
			}
		}
		mini = mininarr();
	}
	return 0;
}
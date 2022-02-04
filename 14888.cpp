#include <bits/stdc++.h>

using namespace std;

int operation[4];
int numbers[11];
int my_max = -1000000001;
int my_min = 1000000001;
int n;

void max_operation(int idx,int result)
{
	if (idx == n - 1) {
		if (my_max < result)
			my_max = result;
		if (my_min > result)
			my_min = result;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (operation[i] > 0)
		{
			operation[i]--;
			switch (i) {
			case 0: 
				max_operation(idx + 1,result + numbers[idx+1]);
				break;
			case 1:
				max_operation(idx + 1, result - numbers[idx+1]);
				break;
			case 2:
				max_operation(idx + 1, result * numbers[idx+1]);
				break;
			case 3:
				max_operation(idx + 1, result / numbers[idx+1]);
			}
			operation[i]++;
		}
	}			
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
	}
	for (int i = 0; i < 4; ++i)
	{
		cin >> operation[i];
	}
	max_operation(0, numbers[0]);
	cout << my_max << '\n' << my_min;
}
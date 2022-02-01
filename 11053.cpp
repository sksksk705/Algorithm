#include <bits/stdc++.h>

using namespace std;

int cache[1001];
int num_list[1001];
int n;
int lis(int start)
{
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = start+1; i <= n; ++i)
	{
		if (num_list[i] > num_list[start])
			ret = max(ret, lis(i)+1);
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num_list[i];
	}
	memset(cache, -1, sizeof(cache));
	int maxVal = -1;
	for (int i = 1; i <= n; ++i)
	{
		maxVal = max(maxVal, lis(i));
	}
	cout << maxVal;
} 
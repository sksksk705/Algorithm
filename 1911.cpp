#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> water;
int main()
{
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
	{
		int start, end;
		cin >> start >> end;
		water.push_back(pair<int,int>(start, end));
	}
	sort(water.begin(), water.end());
	int prev = -1;
	int result = 0;
	for (auto w : water)
	{
		if (w.second <= prev)
			continue;
		if (prev < w.first)
			prev = w.first;
		while (w.second > prev)
		{
			result++;
			prev += l;
		}
	}
	cout << result;

}
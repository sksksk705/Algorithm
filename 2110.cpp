#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> house;
int n;
int c;
int main()
{
	cin >> n;
	cin >> c;
	for (int i = 0; i < n; ++i)
	{
		int h;
		cin >> h;
		house.push_back(h);
	}
	sort(house.begin(), house.end());
	int high = house[n-1] - house[0];		//최대 거리 설정을 해줘야함.
	int low = 0;
	int ans = 0;
	while (low <= high)
	{
		int cnt = 1;
		int mid = (high + low) / 2;
		int prev = house[0];
		for (int i = 1; i < n; ++i)
		{
			if(house[i] - prev >= mid){
				cnt++;
				prev = house[i];
			}
		}
		if (cnt >= c)
		{
			low = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else
			high = mid - 1;
	}
	cout << ans;
	return 0;
}
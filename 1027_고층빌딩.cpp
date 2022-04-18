//2022_04_15 계산기하
//1027번 고층빌딩

//실수 자료형 오차가 생길 수도 있다?
//13:19분 포기
#include <bits/stdc++.h>

using namespace std;

int n;
double height[50];
enum{FRONT,BACK};

int canSee(int start, int end, int dir)
{
	if (dir == FRONT) {
		if (height[end] < height[start])
			return 0;
	}
	else
		if (height[start] < height[end])
			return 0;

	int minHeight = dir == FRONT ? height[start] : height[end];
	int minidx = dir == FRONT ? start :end;


	for (int mid = start + 1; mid < end;++mid)
	{
		if (height[mid] < minHeight)
			continue;
		//두 빌딩이 이루는 기울기보다 해당 건물과의 기울기가 작다면 볼 수 없다.
		if ((height[mid] - minHeight) * (end - start) >= abs(height[start] - height[end]) * abs(mid - minidx))
			return 0;
	}
	return 1;
}

int solve() {
	int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		int buildCanSee = 0;
		int left = 0;
		int right = 0;
		for (int j = i - 1; j >= 0; --j)
		{
			left += canSee(j, i, FRONT);
		}
		for (int j = i+1; j < n; ++j)
		{
			right += canSee(i,j,BACK);
		}
		buildCanSee = left + right;
		ans = max(buildCanSee, ans);
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> height[i];
	int ans = solve();
	cout << ans;
}
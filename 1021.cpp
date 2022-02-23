#include <bits/stdc++.h>

using namespace std;

int roating_queue(int n, int m)
{
	int cnt = 0;
	deque<int> container;
	for (int i = 1; i <= n; ++i)
	{
		container.push_back(i);
	}

	for (int i = 0; i < m; ++i)
	{
		int goal;
		cin >> goal;
		deque<int> left = container;
		deque<int> right = container;
		int left_cnt, right_cnt;
		left_cnt = right_cnt = 0;
		while (right.front() != goal)
		{
			right.push_back(right.front());
			right.pop_front();
			right_cnt++;
		}
		while (left.front() != goal)
		{
			left.push_front(left.back());
			left.pop_back();
			left_cnt++;
		}
		if (left_cnt < right_cnt) {
			container = left;
			cnt += left_cnt;
		}
		else {
			container = right;
			cnt += right_cnt;
		}
		container.pop_front();
	}
	return cnt;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << roating_queue(n, m);
}
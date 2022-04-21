//2022_04_21 랜덤문제풀이
//13904번 과제

//모든 과제가 다 말일까지 할 수 있을 때 완탐의 시간 복잡도 O(N!)
//전날에 한 과제가 다음 날에 영향을 주기 때문에 부분문제가 안 된다.
//그리디로 해결하는 것이 현명할 것 같은데 기준을 어떻게 할까?
//가장 높은 애를 먼저할까? 그럼 1일차가 2순위 일때 할 수가 없다..
//거꾸로 하면 될 거 같다. 마지막 날부터 할 수 있는 것 중에 가장 높은 점수를 하면 될 듯.
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	//총 1000일이 있을 수 있으니 공간을 넉넉히 잡아줘야 함.
	vector<vector<int>> task(1001);
	int lastday = 0;
	for (int i = 0; i < n; ++i)
	{
		int day, point;
		cin >> day >> point;
		task[day].push_back(point);
		lastday = max(day, lastday);
	}
	priority_queue<int> pq;

	int result = 0;
	for (int i = lastday; i > 0; --i)
	{
		for (auto point : task[i])
			pq.push(point);

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}
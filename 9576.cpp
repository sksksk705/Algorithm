#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
struct cmp {
	bool operator()(pair<int, int> stu1, pair<int, int> stu2)
	{
		if (stu1.second == stu2.second)
			return stu1.first > stu2.first;
		return stu1.second > stu2.second;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		int a, b;
		vector<pair<int, int>> student;						//케이스가 많을 때 초기화를 잊지 말자
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			student.emplace_back(make_pair(a, b));
		}
		sort(student.begin(), student.end());
		priority_queue<pair<int, int>,vector<pair<int,int>>, cmp> pq;
		int idx = 0;
		int result = 0;
		for (int i = 1; i <= n; ++i)
		{
			while (idx < m && student[idx].first <= i) {
				pq.push(student[idx]);
				idx++;
			}
			while (!pq.empty() && pq.top().second < i)
			{
				pq.pop();
			}
			if (!pq.empty())
			{
				
				result++;
				pq.pop();
			}
		}
		cout << result << '\n';
	}
}
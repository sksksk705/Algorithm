#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int>> problem;
priority_queue<int> solved;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first > b.first;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int dead, ramen;
		cin >> dead >> ramen;
		problem.push_back(pair<int, int>(dead, ramen));
	}
	sort(problem.begin(), problem.end(), cmp);
	int time = n;
	int idx = 0;
	int result = 0;
	while (time > 0)
	{
		while (idx < n && problem[idx].first >= time)
		{
			solved.push(problem[idx].second);
			idx++;
		}
		if (!solved.empty()) {
			result += solved.top();
			solved.pop();
		}
		time--;
	}
	cout << result;

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> sensor;
int n, k;
priority_queue<int> pq;

int main()
{
	cin >> n>>k;
	int high = 0;
	for (int i = 0; i < n; ++i)
	{
		int pos;
		cin >> pos;
		if (pos > high)
			high = pos;
		sensor.push_back(pos);
	}
	sort(sensor.begin(), sensor.end());
	for (int i = 1; i < n; ++i)
	{
		pq.push(sensor[i] - sensor[i - 1]);
	}
	for (int i = 1; i < k; ++i)
	{
		if(!pq.empty())
			pq.pop();
	}
	int result = 0;
	while (!pq.empty())
	{
		result += pq.top();
		pq.pop();
	}
	cout << result;
}
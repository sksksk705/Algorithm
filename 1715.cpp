#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int card;
		cin >> card;
		pq.push(card);
	}
	int total_sum = 0;
	while (true)
	{
		int small = pq.top();
		pq.pop();
		if (pq.empty()) {
			cout << total_sum;
			break;
		}
		int small2 = pq.top();
		pq.pop();
		int sum = small + small2;
		pq.push(sum);
		total_sum += sum;
	}
	return 0;
}
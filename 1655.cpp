#include <iostream>
#include <queue>
#define FASTIO			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int main()
{
	FASTIO;
	priority_queue<int, vector<int>, greater<int>> minheap;
	priority_queue<int> maxheap;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int now_num;
		cin >> now_num;
		if (maxheap.size() == 0)
			maxheap.emplace(now_num);
		else {
			if (maxheap.top() < now_num)
				minheap.emplace(now_num);
			else
				maxheap.emplace(now_num);

			if (maxheap.size() - minheap.size() == 2)
			{
				minheap.emplace(maxheap.top());
				maxheap.pop();
			}
			else if (minheap.size() > maxheap.size())
			{
				maxheap.emplace(minheap.top());
				minheap.pop();
			}
		}
		cout << maxheap.top() << '\n';
	}
}
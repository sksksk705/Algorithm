#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int operation;
		cin >> operation;
		if (operation == 0)
		{
			if (pq.empty()) {
				cout << 0<<'\n';
				continue;
			}
			cout << pq.top()<<'\n';
			pq.pop();
			continue;
		}
		pq.push(operation);
	}
}
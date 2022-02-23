#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, greater<int>> heap;
	
	int n;
	cin >> n;
	int operation;
	for (int i = 0; i < n; ++i)
	{
		cin >> operation;
		if (operation == 0)
		{
			if (heap.size() != 0) {
				cout << heap.top()<<'\n';
				heap.pop();
				continue;
			}
			cout << "0\n";
			continue;
		}
		heap.emplace(operation);
	}
}
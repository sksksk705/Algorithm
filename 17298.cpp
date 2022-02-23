#include <bits/stdc++.h>

using namespace std;

void NGE(int n, const vector<int>& container)
{
	stack<int> nge; 
	stack<int> idx;
	nge.push(container[0]);
	idx.push(0);
	vector<int> result;
	result.push_back(-1);
	for (int i = 1; i < n; ++i)
	{
		while (container[i] > nge.top())
		{
			result[idx.top()] = container[i];
			idx.pop();
			nge.pop();
			if (nge.empty())
				break;
		}
		result.push_back(-1);
		idx.push(i);
		nge.push(container[i]);	
	}
	for (auto elem : result)
		cout << elem << " ";
}
int main()
{
	int n;
	cin >> n;
	vector<int> container;
	for (int i = 0; i < n; ++i)
	{
		int elem;
		cin >> elem;
		container.push_back(elem);
	}
	NGE(n, container);
}
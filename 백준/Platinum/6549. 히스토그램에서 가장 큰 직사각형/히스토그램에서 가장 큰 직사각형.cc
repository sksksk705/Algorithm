#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 0)
	{
		vector<long long> fences(n+1,0);
		for (int i = 0; i < n; ++i)
			cin >> fences[i];

		stack<int> s;
		long long ret = -1;
		for (int i = 0; i < fences.size(); ++i)
		{
			while (!s.empty() && fences[s.top()] >= fences[i])
			{
				int j = s.top(); s.pop();
				int width = -1;
				if (s.empty())
					width = i;
				else
					width = i - s.top() - 1;
				ret = max(ret, width * fences[j]);
			}
			s.push(i);
		}
		cout << ret<<'\n';
		cin >> n;
	}
}
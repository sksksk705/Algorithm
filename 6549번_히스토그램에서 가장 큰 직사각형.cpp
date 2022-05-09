//2022_05_09 플레티넘 문제
//6549번 히스토그램에서 가장 큰 직사각형

//알고스팟의 FENCE와 같은 문제
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
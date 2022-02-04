#include <bits/stdc++.h>

using namespace std;

vector<int> ss;
string operation;
stack<int> s;
bool stack_sequence(int n)
{
	int now_num = 0;
	s.push(now_num);
	int idx = 0;
	while (idx < n && now_num <= n)
	{
		if (s.top() == ss[idx])
		{
			idx++;
			s.pop();
			operation += '-';
			continue;
		}
		operation += '+';
		s.push(++now_num);

	}
	if (operation.size() < n * 2) {
		operation = "NO"; 
		return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		ss.push_back(num);
	}
	if (stack_sequence(n)) {
		for (auto c : operation)
			cout << c << '\n';
		return 0;
	}
	cout << operation;
	return 0;
}
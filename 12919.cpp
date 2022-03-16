#include <bits/stdc++.h>

using namespace std;

bool makeAB(const string& s, string to) {
	if (to.size() == s.size()) {
		if (to == s)
			return true;
		return false;
	}
	if (to.back() == 'A')
	{
		to.pop_back();
		if (makeAB(s, to))
			return true;
		to.push_back('A');
	}
	if (to.front() == 'B')
	{
		reverse(to.begin(), to.end());
		to.pop_back();
		if (makeAB(s, to))
			return true;
		to.push_back('B');
	}
	return false;
}

int main()
{
	string from, to;
	cin >> from >>to;

	cout<< makeAB(from, to);
}
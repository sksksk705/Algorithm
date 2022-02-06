#include <bits/stdc++.h>

using namespace std;

stack<char> openStack;
string open("([");
string close(")]");

bool isBalance(const string& s)
{
	auto it = s.begin();
	
	for (; it != s.end(); ++it)
	{
		if (open.find(*it) != string::npos)
			openStack.push(*it);
		else if(close.find(*it) != string::npos) {
			if (openStack.empty()) return false;
			if (close.find(*it) != open.find(openStack.top())) return false;
			openStack.pop();
		}
	}
	return openStack.empty();
}

int main()
{
	string s;
	getline(cin, s);
	while (s != ".")
	{
		while (!openStack.empty())
			openStack.pop();
		if (isBalance(s))
			cout << "yes\n";
		else
			cout << "no\n";
		getline(cin, s);
	}
}
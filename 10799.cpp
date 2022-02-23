#include <bits/stdc++.h>

using namespace std;

int cut_pipe(const string& s)
{
	int frag = 0;
	stack<int> pipe;
	for (int i = 0; i < s.size()-1; ++i)
	{
		if (s[i] == '(')
		{
			if (s[i + 1] == ')')
			{
				frag += pipe.size();
				i++;
			}
			else
				pipe.push('(');
		}
		else
		{
			pipe.pop();
			frag++;
		}
	}
	return frag + pipe.size();
}

int main()
{
	string s;
	getline(cin, s);

	int result = cut_pipe(s);
	cout << result;
}
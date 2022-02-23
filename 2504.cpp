#include <bits/stdc++.h>

using namespace std;

string str;
string opening("([");
string closing(")]");

bool check()
{
	stack<char> s;
	for (auto c : str)
	{
		if (opening.find(c) != string::npos)
		{
			s.push(c);
		}
		else
		{
			if (s.empty()) return false;
			if (opening.find(s.top()) == closing.find(c))
				s.pop();
			else 
				return false;
		}
	}
	return s.empty();
}

int calculation()
{
	stack<pair<int, int>> cal;
	int num = 0;
	int result = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (opening.find(str[i]) != string::npos)
		{
			cal.push(make_pair(opening.find(str[i]) + 2,num));
			num++;
			continue;
		}
		else
		{
			int small_result = 0;
			num--;
			while (cal.top().second > num)
			{
				small_result += cal.top().first;
				cal.pop();
			}
			if (small_result == 0) {
				small_result = cal.top().first;
			}
			else {
				small_result *= cal.top().first;
			}
			cal.pop();
			if (cal.empty()) {
				result += small_result;
				continue;
			}
			cal.push(make_pair(small_result, num));
		}
	}
	return result;
}

int main()
{

	cin >> str;
	
	if (!check()) {
		cout << 0;
		return 0;
	}

	int result = calculation();
	cout << result;
}
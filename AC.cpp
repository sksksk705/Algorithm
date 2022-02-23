#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <deque>

using namespace std;
string operation;
string s;
int n;
deque<int> decoded;
bool front = true;
void decode()
{
	int idx = 0;
	while (decoded.size() != n)
	{
		string num;
		if (isdigit(s[idx])) {
			while (isdigit(s[idx]))
			{
				num += s[idx++];
			}
		}
		if (num != "")
			decoded.push_back(stoi(num));
		else
			idx++;
	}
}

string operating()
{
	for (auto op : operation)
	{
		switch (op)
		{
		case 'R':
			front = !front;
			break;
		case 'D':
			if (decoded.empty()) return "error";
			if (front)
				decoded.pop_front();
			else
				decoded.pop_back();
		default:
			break;
		}
	}
	if (!front)
		reverse(decoded.begin(), decoded.end());
	stringstream ss;
	ss << '[';
	for (auto elem : decoded)
	{
		ss << elem << ',';
	}
	string result;
	ss >> result;
	if(result.back() == ',')
		result.pop_back();
	result += ']';
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int p;
	cin >> p;
	for (int i = 0; i < p; ++i)
	{
		cin >> operation;
		cin >> n;
		cin >> s;
		front = true;
		decoded.clear();
		decode();
		string result = operating();
		cout << result<<'\n';
	}
	return 0;
}
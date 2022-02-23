#include <iostream>
#include <string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	str.reserve(600001);
	cin >> str;
	string::iterator it = str.end();
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		char operation;
		cin >> operation;
		switch (operation)
		{
		case 'P':
			char c;
			cin >> c;
			str.insert(it, c);
			it++;
			break;
		case 'L':
			if (it == str.begin())
				break;
			it--;
			break;
		case 'D':
			if (it == str.end())
				break;
			it++;
			break;
		case 'B':
			if (it == str.begin())
				break;
			str.erase(--it);
			break;
		default:
			cout << "wrong operation'\n'";
			break;
		}
	}
	cout << str;
}
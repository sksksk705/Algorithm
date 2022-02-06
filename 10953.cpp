#include <iostream>
#include <string>

using namespace std;
int main()
{
	int n;
	cin >> n;
	while (cin.get() != '\n')
		continue;
	string s;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, s);
		cout << s[0] - 48 + s[2] - 48<<'\n';
	}
}
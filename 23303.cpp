#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	getline(cin,s);
	for (string::iterator it = s.begin(); it != s.end();) {
		if (*it == 'D' || *it == 'd') {
			if (*(++it) == '2') {
				cout << "D2";
				return 0;
			}
			continue;
		}
		++it;
	}
	cout << "unrated";
	return 0;
}
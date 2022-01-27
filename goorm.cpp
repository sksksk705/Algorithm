#include <iostream>
#include <string>

using namespace std;

int main() {
	int result = 0;
	string s;
	getline(cin, s);

	bool isword = false;
	for (auto w : s) {
		if (w!=' '&&isword == false) {
			result++;
			isword = true;
		}
		if (w == ' ')
			isword = false;
	}
	cout << result;
}
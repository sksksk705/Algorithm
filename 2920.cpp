#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	char c[101]{0};
	cin.getline(c,100);

	for (int i = 0; i < 11; ++i) {
		for (int j = i * 10; j < i * 10 + 10; ++j) {
			if (!c[j])
				return 0;
			cout << c[j];
		}
		cout << '\n';
	}

}
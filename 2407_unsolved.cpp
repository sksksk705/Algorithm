#include <iostream>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	double result = 1;
	for (int i = m; i >= 1; i--) {
		result *= n--;
		result /= i;
 	}
}
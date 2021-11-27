#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	double result = 1.;

	for (int i = k; i > 0; --i) {
		result *= n--;
		result /= i;

	}

	cout << result;
}
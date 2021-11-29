#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int burger[3];
int liquid[2];
vector<int> set;
int main() {
	for (int i = 0; i < 3; ++i) {
		int price;
		cin >> price;
		burger[i] = price;
	}
	for (int i = 0; i < 2; ++i) {
		int price;
		cin >> price;
		liquid[i] = price;
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			set.push_back(burger[i] + liquid[j] - 50);
		}
	}

	cout << *min_element(set.begin(), set.end());
}
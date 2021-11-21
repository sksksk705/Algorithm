#include <bits/stdc++.h>

using namespace std;

int main() {
	int result = 0;
	int k;
	int temp;
	vector<int> num_list;

	cin >> k;

	for (int i = 0; i < k; ++i) {
		cin >> temp;
		if (temp == 0)
			num_list.pop_back();
		else
			num_list.push_back(temp);
	}

	for (auto a : num_list)
		result += a;

	cout << result;
}
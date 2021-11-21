#include <bits/stdc++.h>

using namespace std;

int main() {

	int board, land;

	vector<int> station;
	int passanger = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> land >> board;
		passanger += board - land;
		station.push_back(passanger);
	}
	sort(station.begin(), station.end(), greater<int>());
	cout << station.front();


}
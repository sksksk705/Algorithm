#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	vector<int> vec;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> M;
		vec.push_back(M);
	}

	sort(vec.begin(), vec.end());

	int mean = 0;
	for (auto a : vec) {
		mean += a;
	}
	mean = round((double)mean / N);

	int median;
	median = vec[N / 2];

	vector<pair<int, int>> frequency;
	int cnt = 0;
	int mode = vec[0];
	for (auto a : vec) {
		if (a == mode)
			++cnt;
		else {
			frequency.push_back(make_pair(cnt, mode));
			mode = a;
			cnt = 1;
		}
	}
	frequency.push_back(make_pair(cnt, mode));

	sort(frequency.begin(), frequency.end());
	cnt = 0;
	for (auto i : frequency) {
		if (cnt == 2)break;
		if (i.first == frequency.back().first) {
			mode = i.second;
			++cnt;
		}
	}

	int range = vec.back() - vec.front();

	cout << mean << "\n"
		<< median << "\n"
		<< mode << "\n"
		<< range << "\n";

}
#include <bits/stdc++.h>

using namespace std;

int timenumCase[4][4]{
	{1,2,3,4},
	{2,3,4,1},
	{3,4,1,2},
	{4,1,2,3}
};

int getTimenum(vector<int> numvec) {

	priority_queue<int,vector<int>,greater<int>> sortedTimenum;
	for (int i = 0; i < 4; ++i) {
		int num = 0;
		for (int j = 0; j < 4; ++j) {
			num += numvec[timenumCase[i][3-j]-1] * pow(10, j);
		}
		sortedTimenum.emplace(num);
	}
	return sortedTimenum.top();
}


int main() {
	vector<int> num_vec;
	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		num_vec.push_back(num);
	}

	int timenum = getTimenum(num_vec);

	set<int> timenumSet;
	for (int i = 1111; i <= timenum; ++i) {
		vector<int> temp;
		string s = to_string(i);
		for (int j = 0; j < 4; ++j) {
			if (s[j] == '0') {
				temp.clear();
				break;
			}
				temp.push_back(s[j] - '0');
		}
		if (temp.empty())
			continue;
		int tempTimenum = getTimenum(temp);
		timenumSet.insert(tempTimenum);
	}
	cout << timenumSet.size();
}



#include <bits/stdc++.h>
#include <string>

using namespace std;

pair<int, int> findKeyPos(vector<char> a, char c) {
	int pos = 0;
	for (auto m : a)
		if (m == c)
			break;
		else
			pos++;

	return(make_pair(pos / 6, pos % 6));
}

int main() {
	char left;
	char right;
	cin >> left >> right;
	pair<int, int> left_prev;
	pair<int, int> left_now;
	pair<int, int> right_prev;
	pair<int, int> right_now;


	vector<char> za{ 'q','w','e','r','t','0',
					'a','s','d','f','g','0',
					'z','x','c','v'};

	vector<char> mo{'0','y','u','i','o','p',
					'0','h','j','k','l','0',
					'b','n','m' };
	left_prev = findKeyPos(za, left);
	right_prev = findKeyPos(mo, right);


	string goal;
	cin >> goal;

	int result = 0;

	for (int i = 0; i < goal.size(); ++i) {
		result += 1;
		auto isleft = find(za.begin(), za.end(), goal[i]);
		if (isleft == za.end()) {
			right_now = findKeyPos(mo, goal[i]);
			result += abs(right_now.first - right_prev.first) + abs(right_now.second - right_prev.second);
			right_prev = right_now;
		}
		else {
			left_now = findKeyPos(za, goal[i]);
			result += abs(left_now.first - left_prev.first) + abs(left_now.second - left_prev.second);
			left_prev = left_now;
		}
	}

	cout << result;
}


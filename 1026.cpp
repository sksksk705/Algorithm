#include <bits/stdc++.h>

using namespace std;



int main() {
	int n = 0, s = 0, num = 0;

	cin >> n;
	priority_queue<int, vector<int>, less<int>> a;
	priority_queue<int, vector<int>, greater<int>> b;

	for (int j = 0; j < n; ++j) {
		cin >> num;
		a.push(num);
	}

	for (int j = 0; j < n; ++j) {
		cin >> num;
		b.push(num);
	}

	for (int i = 0; i < n; ++i) {
		s += a.top() * b.top();
		a.pop();
		b.pop();
	}

	cout << s;
}
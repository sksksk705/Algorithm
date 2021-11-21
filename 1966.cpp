#include <bits/stdc++.h>

using namespace std;


int main() {
	int t, n, m;
	int rating;

	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n >> m;
		int count = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int j = 0; j < n; ++j) {
			cin >> rating;
			q.push({ j,rating });
			pq.push(rating);
		}
		
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;

			q.pop(); //무조건 queue에서 pop

			if (pq.top() == value) {
				pq.pop();
				++count;

				if (index == m) {
					cout << count << endl;
				}
			}
			else q.push({ index , value }); //일치하지 않으면 다시 push
		}
	}
}
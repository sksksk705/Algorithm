#include <bits/stdc++.h>

using namespace std;

int table[101];

set<int> final;

void bfs(int i){
	 bool visited[101]; //배열을 함수 내에서 초기화하기 때문에 {0}으로 바꿔줘야함.
	vector<int> num_vec;
	num_vec.push_back(i);
	int result = 0;
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while (!q.empty()) {
		result++;
		int now = q.front();
		q.pop();
		int next = table[now];
		num_vec.push_back(next); //순환하는 모든 요소를 벡터에 넣기(순환하지 않으면 초기화)
		if (next == i) {
			for (auto num : num_vec)
				final.insert(num); //만약 순환한다면 집합에 추가
		}
		if (!visited[next]) {
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int m;
		cin >> m;
		table[i] = m;
		
	}
	for (int i = 1; i <= n; ++i) {
		bfs(i);
	}
	
	cout << final.size()<<'\n'; //집합에 있는 갯수
	for (auto a = final.begin(); a != final.end(); ++a) {
		cout << *a << '\n'; // 집합 출력
	}
}
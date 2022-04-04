//2022_04_04 랜덤문제풀이
//2252 줄 세우기

//22:58 분 정답
//23:23 위상 정렬 공부 끝 
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> height(32005);
set<int> students[32005];
int n, m;
void solve1() {
	//모두의 키를 최대로 설정
	for (int i = 1; i <= n; ++i) {
		height[i].first = 100000;
		height[i].second = i;
	}

	// front, back: 큰 아이, 작은 아이
	// back이 front보다 크거나 같으면 back = front -1;
	// front_set에 back을 추가
	// back이 back_set에 있는 아이보다 작아지면 back_set의 큰 아이 = back;
	// 모든 back_set에 있는 아이들 키 -1;
	for (int i = 0; i < m; ++i) {
		int front, back;
		cin >> front >> back;
		if (height[back].first >= height[front].first)
			height[back].first = height[front].first - 1;
		students[front].emplace(back);
		for (auto behind : students[back]) {
			if (height[behind].first >= height[back].first)
				height[behind].first = height[back].first;
			height[behind].first--;
		}
	}
	sort(height.begin(), height.end(), greater<pair<int, int>>());

	for (int i = 0; i < n; ++i)
		cout << height[i].second << " ";
}


int indegree[32001];
vector<int> line;
list<int> graph[32001];
void solve2() {
	for (int i = 0; i < m; ++i) {
		int front, back;
		cin >> front >> back;
		indegree[back]++;
		graph[front].push_back(back);
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= n; ++i) {
		if (q.empty()) {
			assert("사이클 발생");
			return;
		}
		int front = q.front();
		q.pop();
		line.push_back(front);
		for (auto behind : graph[front]) {
			indegree[behind]--;
			if (indegree[behind] == 0)
				q.push(behind);
		}
	}
	for (auto student : line) {
		cout << student << " ";
	}
}

int main() {

	cin >> n >> m;
	//solve1();
	solve2();
}
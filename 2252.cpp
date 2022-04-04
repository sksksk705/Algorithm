//2022_04_04 ��������Ǯ��
//2252 �� �����

//22:58 �� ����
//23:23 ���� ���� ���� �� 
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> height(32005);
set<int> students[32005];
int n, m;
void solve1() {
	//����� Ű�� �ִ�� ����
	for (int i = 1; i <= n; ++i) {
		height[i].first = 100000;
		height[i].second = i;
	}

	// front, back: ū ����, ���� ����
	// back�� front���� ũ�ų� ������ back = front -1;
	// front_set�� back�� �߰�
	// back�� back_set�� �ִ� ���̺��� �۾����� back_set�� ū ���� = back;
	// ��� back_set�� �ִ� ���̵� Ű -1;
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
			assert("����Ŭ �߻�");
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
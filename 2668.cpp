#include <bits/stdc++.h>

using namespace std;

int table[101];

set<int> final;

void bfs(int i){
	 bool visited[101]; //�迭�� �Լ� ������ �ʱ�ȭ�ϱ� ������ {0}���� �ٲ������.
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
		num_vec.push_back(next); //��ȯ�ϴ� ��� ��Ҹ� ���Ϳ� �ֱ�(��ȯ���� ������ �ʱ�ȭ)
		if (next == i) {
			for (auto num : num_vec)
				final.insert(num); //���� ��ȯ�Ѵٸ� ���տ� �߰�
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
	
	cout << final.size()<<'\n'; //���տ� �ִ� ����
	for (auto a = final.begin(); a != final.end(); ++a) {
		cout << *a << '\n'; // ���� ���
	}
}
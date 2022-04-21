//2022_04_21 ��������Ǯ��
//1976�� ���డ��

//�÷��̵�ͼ��� �̿��ؼ� ��� ��ο��� ���� �� �ִ� �׷����� ������� ������� �־�� �ɵ�?
#include <bits/stdc++.h>

using namespace std;

bool graph[201][201];


int main() {
	int n,m;
	cin >> n>>m;
	vector<int> trip(m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> graph[i][j];
			//�ڱ� �ڽ����� ���ϴ� ���� �׻� �ִٰ� ����
			if (i == j)
				graph[i][j] = true;
		}

	for (int i = 0; i < m; ++i)
		cin >> trip[i];

	//�÷��̵�ͼ�
	for(int k = 1; k <= n;++k)
		for(int i = 1; i <= n;++i)
			for (int j = 1; j <= n; ++j) {
				if (graph[i][k] && graph[k][j])
					graph[i][j] = true;
			}

	bool can = true;
	for (int i = 0; i < m - 1; ++i) {
		int from = trip[i];
		int to = trip[i + 1];
		if (!graph[from][to]) {
			can = false;
			break;
		}
	}

		
	if (can)
		cout << "YES";
	else
		cout << "NO";
}
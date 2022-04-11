//2022_04_11 ��������Ǯ��
//14938�� �����׶���

//�÷��̵� ���� �˰��� ������ �� ����.
//�ݺ��� DP�� Ȱ���Ѵٴ� �� ���� ������ �˰Ͱ���.
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, m, r;
int graph[101][101];
int item[101];

void input() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; ++i)
		cin >> item[i];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}

	for (int i = 0; i < r; ++i)
	{
		int a, b, l;
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}
}

int solve() {
	for (int k = 1; k <= n; ++k)
		for (int a = 1; a <= n; ++a)
			for (int b = 1; b <= n; ++b)
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		int miniret = 0;
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] <= m)
				miniret += item[j];
		}
		ret = max(ret, miniret);
	}
	return ret;
}

int main() {
	input();
	int result = solve();
	cout << result;
	return 0;
}
//2022_03_28 ��������Ǯ��
//14220 ���ġ �����

//��� ����� ���� �� Ȯ���ϸ鼭 �ּ� �̵��Ÿ��� ����ؾ��� - dp ����� ��?
//���ð� 500���ϱ� ���� ���ü�, ���� �ִ� ���÷� �ϸ� dp ��밡���� ��
//16:31 ����
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int cache[501][500];
int graph[500][500];
int n;

int getShortestPath(int from, int cities) {
	//���̻� ���ø� �湮���� �ʾƵ� �ȴٸ� 0�� ��ȯ
	if (cities == 0)
		return 0;
	int& ret = cache[from + 1][cities];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int to = 0; to < n; ++to) {
		if (from == -1)
			ret = min(ret, getShortestPath(to, cities-1));
		else {
			if (graph[from][to] != 0)
				ret = min(ret, getShortestPath(to, cities - 1) + graph[from][to]);
		}
	}
	return ret;
}


int main() {

	cin >> n;
	for (int from = 0; from < n; ++from)
		for (int to = 0; to < n; ++to)
			cin >> graph[from][to];
	memset(cache, -1, sizeof(cache));
	int ans = getShortestPath(-1, n);
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
	return 0;
}
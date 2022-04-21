//2022_04_21 랜덤문제풀이
//1976번 여행가자

//플로이드와샬을 이용해서 모든 경로에서 닿을 수 있는 그래프를 만든다음 순서대로 넣어보면 될듯?
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
			//자기 자신으로 향하는 길은 항상 있다고 전제
			if (i == j)
				graph[i][j] = true;
		}

	for (int i = 0; i < m; ++i)
		cin >> trip[i];

	//플로이드와샬
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
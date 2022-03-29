//2022_03_28 랜덤문제풀이
//14220 양아치 집배원

//모든 경우의 수를 다 확인하면서 최소 이동거리를 출력해야함 - dp 경우의 수?
//도시가 500개니까 남은 도시수, 현재 있는 도시로 하면 dp 사용가능할 듯
//16:31 정답
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int cache[501][500];
int graph[500][500];
int n;

int getShortestPath(int from, int cities) {
	//더이상 도시를 방문하지 않아도 된다면 0을 반환
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
//2022_04_05 랜덤문제풀이
//1516 게임개발 21:55 시작


//위상정렬
//여러개의 건물은 같이 지어질 수 있다.
//실수1, prirority queue를 사용할 때 인덱스만 사용함
//22:31 정답
#include <bits/stdc++.h>

using namespace std;

int bulidTime[501];
bool graph[501][501];
int inDegree[501];
int n;

void minBulidTime() {
	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int,int>>> pq;
	for (int buliding = 1; buliding <= n; ++buliding) {
		if (inDegree[buliding] == 0)
			pq.push(make_pair(bulidTime[buliding],buliding));
	}

	int prevTime = 0;
	for (int totalBulid = 0; totalBulid < n; ++totalBulid) {
		if (pq.empty()) {
			assert("사이클 발생");
			return;
		}
		auto nowBulid = pq.top();
		pq.pop();
		prevTime = nowBulid.first;
		for (int highTech = 1; highTech <= n; ++highTech) {
			if (graph[nowBulid.second][highTech]) {
				inDegree[highTech]--;
				if (inDegree[highTech] == 0) {
					bulidTime[highTech] += prevTime;
					pq.push(make_pair(bulidTime[highTech],highTech));
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> bulidTime[i];
		int bulidNeed;
		cin >> bulidNeed;
		while (bulidNeed != -1) {
			inDegree[i]++;
			graph[bulidNeed][i] = true;
			cin >> bulidNeed;
		}
	}
	minBulidTime();
	for (int i = 1; i <= n; ++i) {
		cout<<bulidTime[i]<<'\n';
	}
	return 0;
}
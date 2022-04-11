//2022_04_07 랜덤문제풀이
//2412 암벽등반

//양방향 탐색을 해줘다한다는데...이해가 안되서 포기
#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

//cache: 정상부터 해당 홈으로의 최단 거리 
//holes: 홈의 x,y좌표
vector<pair<int, int>> holes;
int n;
bool visited[50000];

//getPath: 바닥으로부터 정상까지의 최단경로
int getPath(int top) {
	queue<pair<int,int>> holeQ;
	queue<int> pathQ;
	queue<int> idxQ;
	holeQ.push(make_pair(0, 0));
	pathQ.push(0);
	idxQ.push(-1);
	while (!holeQ.empty()) {
		auto nowHole = holeQ.front();
		int nowPath = pathQ.front();
		int idx = idxQ.front();
		holeQ.pop(); pathQ.pop(); idxQ.pop();
		int nowX = nowHole.second;
		int nowY = nowHole.first;
		if (nowY == top)
			return nowPath;
		for (int nextHole = idx+1; nextHole < n; ++nextHole) {
			int ny = holes[nextHole].first;
			int nx = holes[nextHole].second;
			if (visited[nextHole] ||
				abs(nx - nowX) > 2 ||
				abs(ny - nowY) > 2)
				continue;
			holeQ.push(holes[nextHole]);
			pathQ.push(nowPath + 1);
			idxQ.push(nextHole);
			visited[nextHole] = true;
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> n>>T;
	for (int i = 0; i < n; ++i) {
		int holeX, holeY;
		cin >> holeX>>holeY;
		holes.push_back(make_pair(holeY, holeX));
	}
	sort(holes.begin(), holes.end());
	int result = getPath(T);
	cout << result;
}
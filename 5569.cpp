//2022_03_26 동적계획법
//5569 출근경로

//만약에 동적 계획법이 아니었다면 BFS로 풀었을지도?
//점화식을 세우는 게 아직 어색해서 완전탐색으로 풀고 있는데 함수가 너무 더러움...
#include <bits/stdc++.h>

const int MOD = 100000;
using namespace std;
int w, h;
int dx[2]{ 0,1 };
int dy[2]{ 1,0 };
int cache[101][101][2][2];

int getPath(int x, int y, bool rotated, bool direction)
{
	//기저사례1: 범위초과
	if (x > w || y > h)
		return 0;
	//기저사례2: 도착
	if (x == w && y == h)
		return 1;
	int& ret = cache[y][x][rotated][direction];
	if (ret != -1)
		return ret;
	int nextx, nexty;

	//그 전에 방향을 바꿨다면 그 방향 그대로 간다
	if (rotated) {
		nextx = x + dx[direction];
		nexty = y + dy[direction];
		ret = getPath(nextx, nexty, false, direction) % MOD;
		ret %= MOD;
	}
	else {
		//시작점이라면 오른쪽, 아래 어느방향이던 갈 수 있다.
		if (x == 1 && y == 1) {
			ret = (getPath(x + dx[direction], y + dy[direction], false, direction) +
				getPath(x + dx[!direction], y + dy[!direction], false, !direction)) % MOD;
		}
		//그 외는 기존 방향대로 가거나 방향을 바꾸거나 할 수 있다.
		else {
			ret = (getPath(x + dx[direction], y + dy[direction], false, direction) +
				getPath(x + dx[!direction], y + dy[!direction], true, !direction)) % MOD;
		}
		ret %= MOD;
	}
	return ret;
}

int main() {
	cin >> w >> h;
	memset(cache, -1, sizeof(cache));
	cout << getPath(1, 1, false, true);
}
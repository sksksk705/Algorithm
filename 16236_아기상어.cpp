//2022_05_13 ssafy대비
//16236번 아기상어

#include <bits/stdc++.h>

using namespace std;



int board[21][21];
bool visited[21][21];
int dx[4]{ 0,-1,1,0 };
int dy[4]{ -1,0,0,1 };
int sharkSize = 2;
int sharkx, sharky;

//물고기 크기가 최대 6까지
int fishes[7];

bool isSmallerFish() {
	for (int i = (sharkSize > 7 ? 6 : sharkSize - 1); i > 0; --i)
	{
		if (fishes[i] > 0)
			return true;
	}
	return false;
}

bool canMove(int x, int y, int n)
{
	if (x < 0 || x >= n || y < 0 || y >= n||
		visited[y][x] || board[y][x] > sharkSize)
		return false;
	return true;
}

int bfs(int& x, int& y, int n) {
	memset(visited, 0, sizeof(visited));
	queue<int> xq;
	queue<int> yq;
	queue<int> valueq;
	visited[y][x] = true;
	xq.push(x);
	yq.push(y);
	valueq.push(0);
	int findDist = 987654321;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	while (!xq.empty()) {
		int _x = xq.front(); xq.pop();
		int _y = yq.front(); yq.pop();
		int value = valueq.front(); valueq.pop();
		if (value >= findDist)
			break;
		for (int i = 0; i < 4; ++i) {
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			if (!canMove(nx, ny, n))
				continue;
			visited[ny][nx] = true;
			xq.push(nx); yq.push(ny);
			valueq.push(value + 1);
			if (board[ny][nx] < sharkSize && board[ny][nx] != 0) {
				findDist = value + 1;
				pq.push(make_pair(ny, nx));
			}
		}
	}
	if (pq.empty())
		return 0;
	int fishy = pq.top().first;
	int fishx = pq.top().second;
	fishes[board[fishy][fishx]]--;
	board[fishy][fishx] = 0;
	y = fishy; x = fishx;
	return findDist;
}

void input(int n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				sharky = i;
				sharkx = j;
				board[i][j] = 0;
				continue;
			}
			fishes[board[i][j]]++;
		}
}

int main() {
	int n;
	cin >> n;
	input(n);
	int ret = 0;
	int fishEat = 0;
	while (isSmallerFish())
	{
		int dist = bfs(sharkx, sharky, n);
		if (dist == 0)
			break;
		ret += dist;
		fishEat++;
		if (fishEat == sharkSize) {
			sharkSize++;
			fishEat = 0;
		}
	}
	cout << ret;
	return 0;
}
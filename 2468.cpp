//2022_03_16

//각 구역을 탐색하면서 물에 이미 잠겨 있다면 리턴
//아니라면 주위의 안 잠긴 부분 체크 모두 잠겨 있다면 1을 리턴

#include <iostream>
#include <cstring>

using namespace std;

int board[100][100];
bool visited[100][100];

int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
int n;

//범위 체크
bool isRange(int y, int x) {
	if (y < 0 || y >= n ||
		x < 0 || x >= n ||
		visited[y][x])
		return false;
	return true;
}
int isLand(int y, int x, int waterH) {
	int result = 0;
	//기저사례1:범위초과
	if (!isRange(y, x))
		return false;
	//기저사례2: 해당타일이 이미 잠김
	if (board[y][x] < waterH)
		return result;
	//해당 타일을 방문한 것으로 처리하고 주위의 잠기지 않은 타일을 방문
	visited[y][x] = true;
	result = 1;
	for (int i = 0; i < 4; ++i) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		isLand(nexty, nextx, waterH);
	}
	return result;
}

int main() {
	cin >> n;
	int maxHeight = -1;	
	for(int i = 0; i < n;++i)
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] > maxHeight)
				maxHeight = board[i][j];
		}

	int ans = -1;
	//최대치까지 해줘야함 " <= "
	for (int k = 0; k <= maxHeight; ++k) {
		int result = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j){
				result += isLand(i, j, k);
			}
		}
		if (result > ans)
			ans = result;
	}
	cout << ans;
}

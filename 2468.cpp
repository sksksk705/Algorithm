//2022_03_16

//�� ������ Ž���ϸ鼭 ���� �̹� ��� �ִٸ� ����
//�ƴ϶�� ������ �� ��� �κ� üũ ��� ��� �ִٸ� 1�� ����

#include <iostream>
#include <cstring>

using namespace std;

int board[100][100];
bool visited[100][100];

int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
int n;

//���� üũ
bool isRange(int y, int x) {
	if (y < 0 || y >= n ||
		x < 0 || x >= n ||
		visited[y][x])
		return false;
	return true;
}
int isLand(int y, int x, int waterH) {
	int result = 0;
	//�������1:�����ʰ�
	if (!isRange(y, x))
		return false;
	//�������2: �ش�Ÿ���� �̹� ���
	if (board[y][x] < waterH)
		return result;
	//�ش� Ÿ���� �湮�� ������ ó���ϰ� ������ ����� ���� Ÿ���� �湮
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
	//�ִ�ġ���� ������� " <= "
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

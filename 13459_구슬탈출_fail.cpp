//2022_04_22 ��������Ǯ��
//13459�� ����Ż��

//������ �������� 10���ȿ� �� �� �ִ��� üũ�ϸ� �ɵ�
//������ �����̴� �� ������ �ƴϾ���...
//�� �״�� �� ������ �ùķ��̼� �ϴ°� �¾ҳ�?
#include <bits/stdc++.h>

using namespace std;

int n, m;
char board[11][11];
pair<int, int> hole;
pair<int, int> red;
pair<int, int> blue;
int dx[4]{0,0,-1,1};
int dy[4]{-1,1,0,0};


pair<int,int> move(pair<int,int> pos, int dir)
{
	int nowy = pos.first;
	int nowx = pos.second;
	while (board[nowy][nowx] == '.')
	{
		if (board[nowy + dy[dir]][nowx + dx[dir]] == '#')
			break;
		board[nowy][nowx] = '#';
		nowy += dy[dir];
		nowx += dx[dir];
	}
	return make_pair(nowy, nowx);
}

void reset(pair<int, int>after, pair<int,int>before, int dir) {

	while (after != before)
	{
		board[before.first][before.second] = '.';
		before.first += dy[dir];
		before.second += dx[dir];
	}
	board[after.first][after.second] = '.';
}

int bruteForce(pair<int,int> goal, int cnt) {
	if (goal == red)
		return 1;

	if (goal == blue)
		return 0;

	if (cnt > 10)
		return 0;

	for (int i = 0; i < 4; ++i)
	{
		int ny = goal.first + dy[i];
		int nx = goal.second + dx[i];
		
		if (board[ny][nx] != '#')
		{
			pair<int, int> movePos;
			movePos = move(goal, i);
			if (bruteForce(movePos, cnt + 1))
				return 1;
			reset(movePos, goal,i);
		}
	}
	return 0;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			switch (board[i][j]) {
			case 'R': 
				red.first = i;
				red.second = j;
				break;
			case 'O':
				hole.first = i;
				hole.second = j;
				board[i][j] = '.';
				break;
			case 'B':
				blue.first = i;
				blue.second = j;
				break;
			}
		}

	int result = bruteForce(hole, 0);
	cout << result;
}



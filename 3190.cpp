#include <bits/stdc++.h>

using namespace std;
int dx[4]{ 0,1,0,-1 };
int dy[4]{ -1,0,1,0 };
enum DIR{T,R,B,L};
const int APPLE = 2;
const int WALL = 1;

struct SNAKE
{

	int x;
	int y;
	int length;
	int move_dir;
	SNAKE() { x = 1; y = 1; length = 1; move_dir = R; }
	void turn_right() { move_dir += 1; if (move_dir == 4) move_dir = T; }
	void turn_left() { move_dir -= 1; if (move_dir == -1) move_dir = L; }
};

SNAKE snake;
int board[102][102];
int total_move = 0;
map<pair<int,int>, int> snake_body;
int n;

void printboard()
{
	for (int i = 0; i <= n + 1; ++i)
	{
		for (int j = 0; j <= n + 1; ++j)
		{
			if (snake.y == i && snake.x == j) {
				cout << 'S' << ' ';
				continue;
			}
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void boardset()
{

	for (int i = 0; i <= n+1; ++i)
	{
		for (int j = 0; j <= n+1; ++j)
		{
			if (i == 0 || j == 0 ||
				i == n+1 || j == n+1)
				board[i][j] = WALL;
		}
	}
}

bool canMove(int nextx, int nexty)
{
	int nowpos = board[nexty][nextx];
	if (nowpos == WALL || snake_body.find(make_pair(nexty, nextx))!= snake_body.end())
		return false;
	if (nowpos == APPLE) {
		for (auto it = snake_body.begin(); it != snake_body.end();it++)
		{
			it->second++;
		}
		snake.length++;
		board[nexty][nextx] = 0;
	}
	return true;
	
}

bool MoveSnake(int move = 101, char dir = 'D')
{
	for (int i = 0; i < move; ++i)
	{
		total_move++;
		for (auto it = snake_body.begin(); it!= snake_body.end();)
		{
			it->second--;
			if (it->second < 1)
				snake_body.erase(it++);
			else
				it++;
		}
		int nextx = snake.x + dx[snake.move_dir];
		int nexty = snake.y + dy[snake.move_dir];
#ifndef ONLINE_JUDGE
#define NDBUG
		printboard();
#endif
		if (!canMove(nextx,nexty))
			return false;
		snake_body.emplace(make_pair(snake.y, snake.x), snake.length);
		snake.x = nextx;
		snake.y = nexty;
	}
	if (dir == 'L')
		snake.turn_left();
	if (dir == 'D')
		snake.turn_right();
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> n >> k;
	boardset();
	for (int i = 0; i < k; ++i)
	{
		int appley, applex;
		cin >> appley >> applex;
		board[appley][applex] = APPLE;
	}
	int L;
	cin >> L;
	queue<int> movement;
	queue<char> direction;
	for (int i = 0; i < L; ++i)
	{
		int move;
		char dir;
		cin >> move >> dir;
		movement.push(move);
		direction.push(dir);
	}
	while (true)
	{
		if (!MoveSnake(movement.front()- total_move, direction.front())) {
			cout << total_move;
			return 0;
		}
		movement.pop();
		direction.pop();
		if (movement.empty())
		{
			MoveSnake();
			cout << total_move;
			return 0;
		}
	}
	return 0;
}
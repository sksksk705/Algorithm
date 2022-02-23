#include <iostream>

using namespace std;
int Map[50][50];
int dx[4]{ 0,1,0,-1 }; //ºÏ,µ¿,³²,¼­
int dy[4]{ -1,0,1,0 };
struct ROBOT
{
	int x;
	int y;
	int dir;
	int rotation;
	int xLimit;
	int yLimit;
	int total_sweep;
	ROBOT() {
		x = 0; y = 0; dir = 0; xLimit = 50; yLimit = 3, rotation = 0, total_sweep = 0;
	}
	ROBOT(int _x, int _y, int _d, int _xL, int _yL)
	{
		x = _x; y = _y; dir = _d; xLimit = _xL; yLimit = _yL, rotation = 0, total_sweep = 0;
	}
	bool check_left()
	{
		int west = dir>0? dir-1:3;
		int nextx = x + dx[west];
		int nexty = y + dy[west];
		if (nextx < 0 || nextx >= xLimit ||
			nexty < 0 || nexty >= yLimit ||
			Map[nexty][nextx] != 0)
			return false;
		return true;
	}
	void go_front()
	{
		int nextx = x + dx[dir];
		int nexty = y + dy[dir];
		x = nextx;
		y = nexty;
		rotation = 0;
	};
	bool check_back()
	{
		int nextx = x - dx[dir];
		int nexty = y - dy[dir];
		if (nextx < 0 || nextx >= xLimit ||
			nexty < 0 || nexty >= yLimit ||
			Map[nexty][nextx] == 1)
			return false;
		return true;
	}
	void go_back()
	{
		int nextx = x - dx[dir];
		int nexty = y - dy[dir];
		x = nextx;
		y = nexty;
		rotation = 0;
	}
	void turn_left()
	{
		dir = dir > 0 ? dir - 1 : 3;
		rotation++;
	}
	bool checkFourDir()
	{
		if (rotation > 3)
			return false;
		return true;
	}
	void sweep_here()
	{
		if (Map[y][x] == 0) {
			Map[y][x] = 2;
			total_sweep++;
		}
	}
};

int main()
{
	int n, m;
	int r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;
	ROBOT cleaner(c, r, d, m, n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> Map[i][j];
		}
	}
	while (true)
	{
		cleaner.sweep_here();
		if (cleaner.check_left())
		{
			cleaner.turn_left();
			cleaner.go_front();
		}
		else {
			if(cleaner.checkFourDir())
				cleaner.turn_left();
			else if (cleaner.check_back())
				cleaner.go_back();
			else
				break;
		}
	}
	cout << cleaner.total_sweep;
}
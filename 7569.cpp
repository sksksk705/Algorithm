#include <iostream>
#include <queue>
using namespace std;


int dx[6]{ -1,1,0,0,0,0 };
int dy[6]{ 0,0,-1,1,0,0 };
int dz[6]{ 0,0,0,0,1,-1 };
int MAP[101][101][101];
bool visited[101][101][101];
int days[101][101][101];
int M, N, H;
const int INF = 987654321;
queue<int> xq;
queue<int> yq;
queue<int> zq;
int checkAllTomato()
{
	int maxDay = -1;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (MAP[i][j][k] == 0)
					return -1;
				if (MAP[i][j][k] == -1)
					continue;
				if (days[i][j][k] > maxDay)
					maxDay = days[i][j][k];
			}
		}
	}
	return maxDay;
}

void bfs()
{
	while (!xq.empty())
	{
		int nowx = xq.front();
		int nowy = yq.front();
		int nowz = zq.front();
		xq.pop();
		yq.pop();
		zq.pop();
		for (int i = 0; i < 6; i++)
		{
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];
			int nextz = nowz + dz[i];
			if (nextx < 0 || nextx >= M ||
				nexty < 0 || nexty >= N ||
				nextz < 0 || nextz >= H)
				continue;
			if (visited[nextz][nexty][nextx] || MAP[nextz][nexty][nextx] != 0)
				continue;
			visited[nextz][nexty][nextx] = true;
			xq.push(nextx);
			yq.push(nexty);
			zq.push(nextz);
			MAP[nextz][nexty][nextx] = 1;
			days[nextz][nexty][nextx] = min(days[nextz][nexty][nextx], days[nowz][nowy][nowx] + 1);
		}
	}
}

int main()
{
	cin >> M >> N >> H;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> MAP[i][j][k];
				days[i][j][k] = INF;
				if (MAP[i][j][k] == 1)
				{
					visited[i][j][k] = true;
					days[i][j][k] = 0;
					xq.push(k);
					yq.push(j);
					zq.push(i);
				}
			}
		}
	}
	bfs();

	int result = checkAllTomato();
	cout << result;
}
#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

const int INF = 987654321;
char MAP[1000][1000];
bool visited[1000][1000][2];	//방문배열도 3차원으로 설정해야 정답을 얻을 수 있음.
int n, m;
int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
int route[1000][1000][2];
void bfs(int _x, int _y)
{
	queue<int> xq;
	queue<int> yq;
	queue<bool> breakwall;
	xq.push(_x);
	yq.push(_y);
	breakwall.push(false);
	while (!xq.empty())
	{
		int nowx = xq.front();
		int nowy = yq.front();
		bool havebreak = breakwall.front();
		xq.pop();
		yq.pop();
		breakwall.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];
			if (nextx < 0 || nextx >= m ||
				nexty < 0 || nexty >= n ||
				visited[nexty][nextx][havebreak])
				continue;
			if (havebreak) {
				if (MAP[nexty][nextx] == '1') {
					continue;
				}
				route[nexty][nextx][1] = min(route[nowy][nowx][1] + 1, route[nexty][nextx][1]);
				visited[nexty][nextx][true] = true;
				xq.push(nextx);
				yq.push(nexty);
				breakwall.push(true);
			}
			else {
				if (MAP[nexty][nextx] == '1') {
					route[nexty][nextx][1] = min(route[nowy][nowx][0] + 1, route[nexty][nextx][1]);
					visited[nexty][nextx][true] = true;
					xq.push(nextx);
					yq.push(nexty);
					breakwall.push(true);
					continue;
				}
				route[nexty][nextx][0] = min(route[nowy][nowx][0] + 1, route[nexty][nextx][0]);
				visited[nexty][nextx][false] = true;
				xq.push(nextx);
				yq.push(nexty);
				breakwall.push(false);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef BOJ
	fstream finout("2206.txt");
	finout >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		finout >> s;
		for (int j = 0; j < m; ++j)
		{
			MAP[i][j] = s[j];
			route[i][j][0] = INF;
			route[i][j][1] = INF;
		}
	}
#endif 

#ifdef BOJ
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
		{
			MAP[i][j] = s[j];
			route[i][j][0] = INF;
			route[i][j][1] = INF;
		}
	}
#endif
	route[0][0][0] = 1;
	visited[0][0][0] = true;
	bfs(0, 0);
	int result = min(route[n-1][m-1][0], route[n-1][m-1][1]);
	if (result == INF)
		result = -1;
	cout << result;
}
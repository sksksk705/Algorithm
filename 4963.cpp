#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int mapi[51][51];
int w, h;
int ans;
int dx[8]{0,0,1,-1,1,1,-1,-1};
int dy[8]{ 1,-1,0,0 ,-1,1,-1,1};
bool visited[51][51];

void findIsland()
{
	queue<int> xq;
	queue<int> yq;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (mapi[i][j] == 1 && !visited[i][j]) {
				visited[i][j] = true;
				xq.push(j);
				yq.push(i);
				ans++;
				while (!xq.empty())
				{
					int nowx = xq.front();
					int nowy = yq.front();
					xq.pop();
					yq.pop();
					for (int k = 0; k < 8; ++k)
					{
						int nextx = nowx + dx[k];
						int nexty = nowy + dy[k];
						if (!visited[nexty][nextx] && mapi[nexty][nextx] == 1 &&
							nextx >= 0 && nextx < w && nexty >= 0 && nexty < h)
						{
							visited[nexty][nextx] = true;
							xq.push(nextx);
							yq.push(nexty);
						}
					}
				}
			}
		}
	}

}

int main()
{
	cin >> w >> h;
	while (w != 0 && h != 0)
	{
		ans = 0;
		memset(mapi, 0, sizeof(mapi));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> mapi[i][j];
			}
		}
		findIsland();
		cout << ans << '\n';
		cin >> w >> h;
	}
}
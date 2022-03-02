#include <bits/stdc++.h>

using namespace std;

bool visited[301][301];
int MAP[301][301];
int dx[4]{ -1,1,0,0 };
int dy[4]{ 0,0,-1,1 };
queue<int> xq;
queue<int> yq;
int n, m;
void bfs() {
    while (!xq.empty()) {
        int nowx = xq.front(); xq.pop();
        int nowy = yq.front(); yq.pop();
        for (int i = 0; i < 4; ++i) {
            int nextx = nowx + dx[i];
            int nexty = nowy + dy[i];
            if (nextx < 0 || nextx >= m ||
                nexty < 0 || nexty >= n ||
                visited[nexty][nextx])
                continue;
            if (MAP[nexty][nextx] == 0) {
                if (MAP[nowy][nowx] > 0) {
                    MAP[nowy][nowx]--;
                }
            }
            else {
                xq.push(nextx);
                yq.push(nexty);
                visited[nexty][nextx] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int days = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> MAP[i][j];
        }
    }
    while (true) {
        bool bricks = false;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (MAP[i][j] != 0) {
                    visited[i][j] = true;
                    xq.push(j);
                    yq.push(i);
                    bricks = true;
                    break;
                }
            }
            if (bricks)
                break;
        }
        if (xq.empty())
            break;
        bfs();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!visited[i][j] && MAP[i][j] != 0) {
                    cout << days;
                    return 0;
                }
        days++;
    }
    cout << 0;
    return 0;
}
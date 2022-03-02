#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
queue<int> toq;
queue<int> distq;
bool member[51][51];
bool visited[51];
int point[51];
int n;
int bfs(int from) {
    int my_point = -1;
    memset(visited, 0, sizeof(visited));
    toq.push(from);
    distq.push(0);
    visited[from] = true;
    while (!toq.empty()) {
        int now = toq.front();    toq.pop();
        int dist = distq.front();    distq.pop();
        if (dist != 0 && dist > my_point)
            my_point = dist;
        for (int i = 1; i <= n; ++i) {
            int next = i;
            if (member[now][next] == 0 || visited[next])
                continue;
            visited[next] = true;
            toq.push(next);
            distq.push(dist + 1);
            point[next] = max(point[next], dist + 1);
        }
    }
    return my_point;
}

int main() {
    cin >> n;
    int from, to;
    cin >> from >> to;
    while (from != -1 && to != -1) {
        member[from][to] = true;
        member[to][from] = true;
        cin >> from >> to;
    }
    int min_point = 987654321;
    for (int i = 1;  i <= n; ++i) {
        min_point = min(bfs(i), min_point);
    }
    int possible = 0;
    vector<int> cand;
    for (int i = 1; i <= n; ++i) {
        if (point[i] == min_point) {
            possible++;
            cand.push_back(i);
        }
    }
    cout << min_point << ' ' << possible << '\n';
    for (int i = 0; i < cand.size(); ++i) {
        cout << cand[i] << ' ';
    }
}
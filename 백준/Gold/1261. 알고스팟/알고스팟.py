import heapq
import sys
input = sys.stdin.readline
# 1,1에서 출발하여 갈 수 있는 모든 블럭을 구한다.
# n,m에서 출발하여 갈 수 있는 모든 블럭을 구한다.
# 두 경우의 수의 간의 거리의 최소 거리를 구하면 부숴야하는 최소의 벽 개수가 나온다.


dx = [1,0,-1,0]
dy = [0,1,0,-1]
def dijkstra(x,y):
  dist = [[987654321] * m for _ in range(n)]
  pq = []
  dist[x][y] = 0
  heapq.heappush(pq,(0,x,y))
  while pq:
    (cur_dist, nowx, nowy) = heapq.heappop(pq)
    for i in range(4):
      nx = nowx + dx[i]
      ny = nowy + dy[i]
      if nx < 0 or ny < 0 or nx >= m or ny >= n:
        continue
      nxt_dist = cur_dist + int(maze[ny][nx])
      if nxt_dist < dist[ny][nx]:
        dist[ny][nx] = nxt_dist
        heapq.heappush(pq,(nxt_dist,nx,ny))
  return dist[n-1][m-1]


m,n = map(int,input().split())
maze = []
for i in range(n):
  maze.append(list(input()))

ans = dijkstra(0,0)
print(ans)
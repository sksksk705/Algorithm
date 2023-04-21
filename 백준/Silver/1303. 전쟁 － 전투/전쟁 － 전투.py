import sys
input = sys.stdin.readline

m,n = map(int,input().split())

board = []
for i in range(n):
  board.append(list(input()))
visited= [[False]*m for _ in range(n)]

white = 0
blue = 0

dx = [0,0,-1,1]
dy = [-1,1,0,0]
def dfs(y,x):
  ret = 1
  for i in range(4):
    ny = y + dy[i]
    nx = x + dx[i]
    if ny < 0 or nx < 0 or ny >= n or nx >= m or board[ny][nx] != board[y][x] or visited[ny][nx]:
      continue
    visited[ny][nx] = True
    ret += dfs(ny,nx)
  return ret

for i in range(n):
  for j in range(m):
    if not visited[i][j]:
      visited[i][j] = True
      if board[i][j] == 'W':
        white += pow(dfs(i,j),2)
      else:
        blue += pow(dfs(i,j),2)
print(white, blue)
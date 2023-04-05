import sys
input = sys.stdin.readline

def dfs(y,x,dist):
  global ans
  if(y == 0 and x == c-1 and dist ==k):
    ans += 1
    return
  for i in range(4):
    ny = y + dy[i]
    nx = x + dx[i]
    if ny < 0 or ny >= r or nx < 0 or nx >= c or visited[ny][nx] or board[ny][nx] == 'T':
      continue
    visited[ny][nx] = True
    dfs(ny,nx,dist+1)
    visited[ny][nx] = False
    
r,c,k = map(int,input().split())
board = []
for i in range(r):
  board.append(list(input()))

dx = [0,0,-1,1]
dy = [1,-1,0,0]
visited= [[False] * c for _ in range(r)]
visited[r-1][0] = True
ans = 0

dfs(r-1,0,1)
print(ans)
import sys
input = sys.stdin.readline

n, m = map(int,input().split())

farm = []
for i in range(n):
  farm.append(list(map(int,input().split())))

visited = [[False] * m for _ in range(n)]
dx = [0,1,1,1,0,-1,-1,-1]
dy = [-1,-1,0,1,1,1,0,-1]

def dfs(i,j):
  visited[i][j] = True
  ret = True
  for d in range(8):
    x = i + dx[d]
    y = j + dy[d]
    if not (0 <= x < n and 0 <= y < m):
      continue
    if farm[x][y] == farm[i][j] and not visited[x][y]:
      visited[x][y] = True
      ret = dfs(x,y) and ret
    elif farm[x][y] > farm[i][j]:
      ret = False
  return ret

cnt = 0
for i in range(n):
  for j in range(m):
    if visited[i][j]:
      continue
    if (dfs(i,j)):
      cnt += 1

print(cnt)
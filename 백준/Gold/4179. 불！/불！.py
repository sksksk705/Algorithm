import sys
input = sys.stdin.readline
dx = [0,0,-1,1]
dy = [-1,1,0,0]

def solution(r,c,maze):
  jihun = []
  fire = []
  for i in range(r):
    for j in range(c):
      if(maze[i][j] == 'J'):
        jihun.append((i,j))
      if(maze[i][j] == 'F'):
        fire.append((i,j))
  
  onFire = [[0]* c for _ in range(r)]
  if fire:
    onFire[fire[0][0]][fire[0][1]] = 1
  
  visited= [[0]* c for _ in range(r)]
  visited[jihun[0][0]][jihun[0][1]] = 1
  
  day = 0
  while jihun:
    day += 1
    size = len(fire)
    for f in range(size):
      (y,x) = fire.pop(0)
      for i in range(4):
        ny = y + dy[i]  
        nx = x + dx[i]  
        if ny >= r or ny < 0 or nx >= c or nx < 0 or maze[ny][nx] == '#' or onFire[ny][nx]:
          continue
        onFire[ny][nx] = 1
        fire.append((ny,nx))
    size = len(jihun)
    for j in range(size):
      (y,x) = jihun.pop(0)
      for i in range(4):
        ny = y + dy[i]  
        nx = x + dx[i]  
        if ny >= r or ny < 0 or nx >= c or nx < 0:
          return day 
        if visited[ny][nx] or onFire[ny][nx] or maze[ny][nx] == '#':
          continue
        visited[ny][nx] = 1
        jihun.append((ny,nx))
  return -1

r,c = map(int,input().split())
maze = []
for i in range(r):
  maze.append(list(input()))
ans = solution(r,c,maze)
if(ans == -1):
  print("IMPOSSIBLE")
else:
  print(ans)
# 아스키 대문자 65 ~ 70, 소문자 97 ~ 102 
from collections import deque
import sys
input = sys.stdin.readline

def outOfRange(x,y):
  return x < 0 or x >= m or y < 0 or y >= n

n,m = map(int,input().split())
maze = []
for i in range(n):
  maze.append(list(input()))

visited= [[[False] * m for _ in range(n)] for _ in range(2**6)]

stx = 0
sty = 0
for i in range(n):
  for j in range(m):
    if maze[i][j] == '0':
      stx = j
      sty = i
      maze[i][j] = '.'

visited[0][sty][stx] = True
q = deque()
dx = [0,0,-1,1]
dy = [-1,1,0,0]
# x좌표, y좌표, 가진 키, 이동횟수
q.append((stx,sty,0,0))
while q:
  nowx, nowy, key, cnt = q.popleft()
  for i in range(4):
    nx = nowx + dx[i]
    ny = nowy + dy[i]
    # 범위 초과
    if(outOfRange(nx,ny)): continue
    # 방문했거나 벽이라면 continue
    if visited[key][ny][nx] or maze[ny][nx] == '#': continue
    cell = maze[ny][nx]
    # 빈칸이면 바로 이동
    if(cell == '.'):
      visited[key][ny][nx] = True
      q.append((nx,ny,key,cnt+1))
    # 출구라면 결과 출력
    elif(cell == '1'):
      print(cnt + 1)
      exit()
    #키
    elif(ord(cell) >= 97):
      #키를 획득한다.
      newkey = key | (1 << ord(cell) - 97)
      visited[key][ny][nx] = True
      visited[newkey][ny][nx] = True
      q.append((nx,ny,newkey,cnt+1))
    #문
    else:
      # 해당하는 키가 없다면 못감.
      if(key & (1 << ord(cell) - 65) == 0):
        continue
      visited[key][ny][nx] = True
      q.append((nx,ny,key,cnt+1))
      
print(-1)
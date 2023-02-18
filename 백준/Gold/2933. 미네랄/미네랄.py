# 2933 미네랄
# r = 높이 ,c = 넓이 ,n = 던진 막대의 수 , h[] = 던진 높이의 배열 (n - h)
# 던져서 처음 만난 미네랄로부터 bfs 하며 cluster[]에 저장 만약 부숴진 미네랄보다 낮은 높이에 연결되어있거나
# 바닥과 붙어있다면 break
# 그 외의 경우 해당 블럭에서 아래로 출발하여 만날 수 있는 바닥이나 미네랄까지의 거리를 계산 후 cluster[]에 들어있는
# 모든 미네랄을 아래로 이동

import sys
from collections import deque
input = sys.stdin.readline

# 데이터 입력
r,c = map(int, input().split())
minerals = []
for i in range(r):
  minerals.append(list(input()))
n = int(input())
h = list(map(int,input().split()))


# 연결된 클러스터를 찾아주는 bfs함수
# 만약 바닥이나 미네랄에 연결되어 있지 않다면 클러스터를 반환하고
# 연결되어 있다면 빈배열[]을 반환한다.
dx = [-1,1,0,0]
dy = [0,0,-1,1]
def bfs(x,y):
  global r,c
  cluster = []
  visited = {}
  queue = deque()

  cluster.append((x,y))
  queue.append((x,y))
  visited[(x,y)] = True

  while(len(queue) > 0):
    (nowx,nowy) = queue.popleft()
    if(nowy == r-1):
      return []
    for i in range(4):
      nx = nowx + dx[i]
      ny = nowy + dy[i]
      if(nx < 0 or nx >= c or ny < 0 or ny >= r or (nx,ny) in visited or minerals[ny][nx] != 'x'):
        continue
      visited[(nx,ny)] = True
      cluster.append((nx,ny))
      queue.append((nx,ny))
  return cluster

def clusterSimulation(x,y):
  minerals[throw][x] = '.'
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if(nx < 0 or nx >= c or ny < 0 or ny >= r or minerals[ny][nx] != 'x'):
      continue
    cluster = bfs(nx,ny)
    if(cluster == []):
      continue
    # 바닥까지 살피는데 중간에 미네랄이 있다면 멈춤
    minDist = 100
    for mineral in cluster:
      (mx,my) = mineral
      dist = 1
      inCluster = False
      while(dist + my < r):
        if(minerals[my+dist][mx] == 'x'):
          if((mx,my+dist) in cluster):
            inCluster = True
          break
        dist += 1
      if(inCluster):
        continue
      minDist = min(dist,minDist)
    #cluster를 아래로 움직여줌
    for mineral in cluster:
      (mx,my) = mineral
      minerals[my][mx] = '.'
    for mineral in cluster:
      (mx,my) = mineral
      minerals[my+minDist-1][mx] = 'x'
    

# 던짐 시뮬레이션(짝수일 경우 왼쪽에서 던짐)
for i in range(n):
  throw = r - h[i]
  x = -1
  if(i % 2 == 0):
    for j in range(c):
      if(minerals[throw][j] == 'x'):
        x = j;
        break;
  else:
    for j in range(c, -1, -1):
      if(minerals[throw][j] == 'x'):
        x = j;
        break;
  if(x != -1):
    clusterSimulation(x,throw)

for i in range(r):
  for j in range(c):
    print(minerals[i][j],end='')
  print()
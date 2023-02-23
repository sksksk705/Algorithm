#한번 인구 이동 할 때마다 visited[]로 만들어서 bfs해주고
# bfs에서 모인 것들 다 평균값 내서 새 배열에 위치에 따라
from collections import deque
import sys
import copy

dx = [-1,1,0,0]
dy = [0,0,-1,1]
population = []
movedPopulation = []

def bfs(x,y,visited):
    global n,l,r
    #이동해야하는 인구를 모아놓는 배열
    group = []
    #이동하는 인구의 평균을 만들기 위한 값
    populationSum = 0
    q = deque()

    q.append((x,y))
    group.append((x,y))
    visited[y][x] = True
    populationSum += population[y][x]

    while(len(q) > 0):
        (nowx,nowy) = q.popleft()
        for i in range(4):
            nx = nowx + dx[i]
            ny = nowy + dy[i]
            if(nx >= n or nx < 0 or ny >= n or ny < 0 or visited[ny][nx]):
                continue
            diff = abs(population[nowy][nowx] - population[ny][nx])
            if(not l <= diff <= r):
                continue
            visited[ny][nx] = True
            populationSum += population[ny][nx]
            group.append((nx,ny))
            q.append((nx,ny))
    populationSum = int(populationSum/len(group))
    for (gx,gy) in group:
        movedPopulation[gy][gx] = populationSum

n,l,r = map(int,sys.stdin.readline().split())
for i in range(n):
    population.append(list(map(int,sys.stdin.readline().split())))

def checkAllSame(n):
    for i in range(n):
        for j in range(n):
            if(population[i][j] != movedPopulation[i][j]):
                return False
    return True

days = 0;
isOver = False
while(True):
    visited = [[False for _ in range(n)]for _ in range(n)]
    for i in range(n):
        movedPopulation = [[0 for i in range(n)]for i in range(n)]
    for i in range(n):
        for j in range(n):
            if(not visited[i][j]):
                bfs(j,i,visited)
    if(checkAllSame(n)):
        isOver = True
        break
    population = copy.deepcopy(movedPopulation)
    days += 1

print(days)
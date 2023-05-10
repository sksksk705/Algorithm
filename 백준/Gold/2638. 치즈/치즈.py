#겉에서부터 dfs. 겉면따라 만나는 1만 없애기
#겉에 치즈 중 4변 중 적어도 2변 이상 겉이랑 접촉하는 것만 한 시간 후 없어짐
import sys
sys.setrecursionlimit(1000000)

R,C = map(int,sys.stdin.readline().rstrip().split())

cheese = []

for _ in range(R):
    cheese.append(list(map(int,sys.stdin.readline().rstrip().split())))

t = 0 #시간
#치즈 아니면 방문체크 치즈면 닿아있는 면 개수 세어줄 것
visited = [[0 for _ in range(C)] for _ in range(R)]

#상하좌우
dx = [-1,1,0,0]
dy = [0,0,-1,1]

sum = 0 #한 시간마다 없어질 치즈, while 종료조건

def dfs(x,y):
    visited[x][y] +=1 #방문체크

    for i in range(4):
        cx = x+dx[i]
        cy = y+dy[i]

        #범위 체크
        if cx<0 or cx>=R or cy<0 or cy>=C:
            continue

        #치즈라면 
        if cheese[cx][cy] == 1: 
            visited[cx][cy] += 1 #인접한 면 개수 추가

        #치즈 없고 방문 안했으면
        elif cheese[cx][cy] == 0 and visited[cx][cy] == 0:
            dfs(cx,cy)

while True:
    #초기화
    for i in range(R):
        for j in range(C):
            visited[i][j] = 0
    sum = 0

    dfs(0,0)

    for i in range(R):
        for j in range(C):
            if cheese[i][j] == 1 and visited[i][j] >=2: #없어질 치즈면
                sum +=1
                cheese[i][j] = 0 #치즈 없애기

    if sum == 0:
        break

    t+=1 #시간 증가

print(t)
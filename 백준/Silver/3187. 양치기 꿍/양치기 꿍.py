import sys
input = sys.stdin.readline

r,c = map(int,input().split())

board =[]
for i in range(r):
    board.append(list(input()))
visited = [[False] * c for _ in range(r)]

def bfs(x,y):
    q = [(x,y)]
    dx = [0,0,-1,1]
    dy = [1,-1,0,0]
    sheep = 0
    wolf = 0
    if board[x][y] == 'v':
        wolf += 1
    elif board[x][y] == 'k':
        sheep += 1
    while q:
        last = q.pop(0)
        for i in range(4):
            nx = last[0] + dx[i]
            ny = last[1] + dy[i]
            if nx < 0 or nx >= r or ny < 0 or ny >= c or visited[nx][ny] or board[nx][ny] == '#':
                continue
            visited[nx][ny] = True
            if board[nx][ny] == 'v':
                wolf += 1
            elif board[nx][ny] == 'k':
                sheep += 1
            q.append((nx,ny))
    if sheep > wolf:
        return [sheep, 0]
    else:
        return [0, wolf]

res = [0,0]
for i in range(r):
    for j in range(c):
        if not visited[i][j] and board[i][j] != '#':
            visited[i][j] = True
            res = [x+y for x,y in zip(res,bfs(i,j))]
print(*res)
import sys
input = sys.stdin.readline

a,b = map(int,input().split())
n,m = map(int,input().split())

graph = [[0] * (n+1) for _ in range(n+1)]
visited = [0] * (n+1)
for i in range(m):
    x,y = map(int,input().split())
    graph[x][y] = 1
    graph[y][x] = 1

q = [a]
visited[a] = 1

while q:
    start = q.pop(0)
    for i in range(1,n+1):
        if graph[start][i] and not visited[i]:
            visited[i] = visited[start]+1
            q.append(i)

print(visited[b]-1)
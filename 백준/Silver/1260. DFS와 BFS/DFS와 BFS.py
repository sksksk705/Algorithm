import sys


input = sys.stdin.readline
n,m,v = map(int,input().split())

graph = [[0]* (n+1) for i in range(n+1)]
visited = [0] * (n+1)

for i in range(m):
    a,b = map(int,input().split())
    graph[a][b] = graph[b][a] = 1

def dfs(v):
    stack = [v]
    # dfs 끝나고 나면 다 1되어있을 거니까 0으로 방문 판정
    visited[v] = 0
    while stack:
        v = stack.pop()
        if(visited[v] == 1):
            continue
        visited[v] = 1
        print(v, end = ' ')
        for i in range(n,0,-1):
            if(visited[i] == 0 and graph[v][i] == 1):
                stack.append(i)
                
def bfs(v):
    queue = [v]
    # dfs 끝나고 나면 다 1되어있을 거니까 0으로 방문 판정
    visited[v] = 0
    while queue:
        v = queue.pop(0)
        print(v, end = ' ')
        for i in range(1,n+1):
            if(visited[i] == 1 and graph[v][i] == 1):
                queue.append(i)
                visited[i] = 0

dfs(v)
print()
bfs(v)
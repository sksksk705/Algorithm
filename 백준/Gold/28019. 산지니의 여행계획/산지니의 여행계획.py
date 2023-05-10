import heapq
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n,m = map(int,input().split())

#최대 신장 트리를 만들어라

graph = [[]for _ in range(n+1)]

for i in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((-c,b,a))
    graph[b].append((-c,a,b))

start = int(input())
pq = []
for edge in graph[start]:
    heapq.heappush(pq,edge)

visited = [False] * (n+1)
visited[start] = True
e = 0
tree = [[] for _ in range(n+1)]
dist = 0
while pq and e < n - 1:
    longEdge = heapq.heappop(pq)
    if visited[longEdge[1]]:
        continue
    for addEdge in graph[longEdge[1]]:
        if visited[addEdge[1]]:
            continue
        heapq.heappush(pq, addEdge)
    visited[longEdge[1]] = True
    dist -= longEdge[0]
    tree[longEdge[2]].append((longEdge[1],-longEdge[0]))
    e += 1

maxDist = 0
visited = [0] * (n+1)
def travel(start,ret):
    global maxDist
    visited[start] = True
    if not tree[start]:
        maxDist = max(maxDist, ret)
        return
    for edge in tree[start]:
        if visited[edge[0]]:
            continue
        travel(edge[0], ret + edge[1])

travel(start,0)
print(dist*2 - maxDist)
import sys

n = int(sys.stdin.readline())

graph = [] 

for _ in range(n):
  graph.append(list(map(int, sys.stdin.readline().split())))


for k in range(n):
  for j in range(n):
    for i in range(n):
      graph[i][j] = graph[i][j] or (graph[i][k] and graph[k][j])

for i in range(n):
  print(*graph[i])
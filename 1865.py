#1865 웜홀
#플로이드와샬 써서 최단 거리 구한 뒤 [i][i]중에 0미만이 있다면 YES

import sys

T = int(sys.stdin.readline())

def floid(graph):
  for k in range(1,n+1):
    for i in range(1,n+1):
      for j in range(1,n+1):
        graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j])
      if(graph[i][i] < 0):
        return True
  return False

for _ in range(T):
  n,m,w = map(int,sys.stdin.readline().split())
  graph = [[1000000000 for _ in range(n+1)] for _ in range(n+1)]
  for i in range(m):
    s,e,t =  map(int,sys.stdin.readline().split())
    graph[s][e] = min(graph[s][e],t)
    graph[e][s] = min(graph[e][s],t)

  for i in range(w):
    s,e,t =  map(int,sys.stdin.readline().split())
    graph[s][e] = min(graph[s][e],-t)

  if(floid(graph)):
    print("YES")
  else:
    print("NO")

import sys

k = int(sys.stdin.readline())
buildings = list(map(int,sys.stdin.readline().split()))

buildTree = [[] for _ in range(k)]

def travel(start,end,k):
  if(start == end):
    return
  root = (start + end) // 2
  buildTree[k].append(buildings[root])
  travel(start,root,k+1)
  travel(root+1,end,k+1)

travel(0,2**k-1,0)

for i in range(k):
  print(*buildTree[i])
import math
from collections import deque
n = int(input())


def bfs(n):
  q = deque()
  visited = [0 for _ in range(50001)]
  q.append((n,0))

  while(len(q) > 0):
    (num, val) = q.popleft()
    for i in range(1,int(math.sqrt(num))+1):
      nextNum = num - i**2
      if(nextNum == 0):
        print(val+1)
        return
      if(visited[nextNum] != 0):
        continue
      visited[nextNum] = 1
      q.append((nextNum,val+1))
      
  
bfs(n)
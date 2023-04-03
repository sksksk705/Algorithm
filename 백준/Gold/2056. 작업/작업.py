from collections import deque
import sys
input = sys.stdin.readline

n = int(input())

indegree = [0] * (n + 1)
time = [0] * (n+1)
spendTime = [0] * (n+1)

graph =[[] for  i in range(n+1)]
for i in range(1,n+1):
  task = list(map(int,input().split()))
  indegree[i] = task[1]
  time[i] = task[0]
  for j in range(2, len(task)):

    graph[task[j]].append(i)
q = deque()
for i in range(1,n+1):
  if indegree[i] == 0:
    q.append(i)

while(q):
  st = q.popleft()
  for i in graph[st]:
    spendTime[i] = max(spendTime[i],time[st])
    indegree[i] -= 1
    if(indegree[i] == 0):
      time[i] = spendTime[i] + time[i]
      q.append(i)
      
print(max(time))
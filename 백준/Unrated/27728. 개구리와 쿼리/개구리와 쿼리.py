#구간합을 반대로 구해서
#모든 y에서 n+1까지의 최소값을 구해놓고
#Sy + i + time[sy+i]를 구하면 될듯
import sys
input = sys.stdin.readline

n,q = map(int,input().split())

pond = []
for i in range(n):
  pond.append(list(map(int,input().split())))

for i in range(n):
  for j in range(n-2,-1,-1):
    pond[i][j] += pond[i][j+1] 

time = [[987654321] * n for _ in range(n)]
time[0] = pond[0][:]
for i in range(1,n):
  for j in range(n):
    time[i][j] = min(time[i][j],pond[i][j],time[i-1][j])
  
for i in range(q):
  sx, sy,l = map(int,input().split())
  sx -= 1
  sy -= 1
  ans = pond[sx][sy]
  for j in range(sy,n):
    ans = min(ans,pond[sx][sy] - pond[sx][j] + time[sx-l][j])
  print(ans)
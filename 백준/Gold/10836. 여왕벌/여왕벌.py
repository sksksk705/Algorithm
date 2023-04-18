import sys
input = sys.stdin.readline

# 제일 위쪽 칸이 0,0
# 제일왼쪽 열과 제일 위쪽 행은 자신이 자라는 정도를 스스로 결정한다
# 이는 입력으로 주어진다.
# 왼쪽 제일 아래에서 위쪽, 도착하면 오른쪽으로 끝까지

# m = 700, n = 1,000,000
# mn = 700,000,000 브루트포스가 안 되네..
m,n = map(int,input().split())

days = [0] * (2*m)

for i in range(n):
  #len(lst) = 2M-1
  lst = list(map(int,input().split()))
  days[lst[0]] += 1
  days[lst[0] +lst[1]] += 1

for i in range(1,2*m):
  days[i]= days[i] + days[i-1]

res = [[1] * m for _ in range(m)]

for i in range(m):
  res[m-i-1][0] += days[i]

for i in range(1,m):
  res[0][i] += days[i+m-1]


# 나머지 자신 왼쪽, 왼쪽 위, 위쪽 (-1,0),(-1,-1),(0,-1)에서 가장 많이 자란 애벌레가 자란만큼
# 즉 (1,1)에서 오른쪽으로 이동하면서 탐색하기
dx = [-1,-1,0]
dy = [0,-1,-1]
for i in range(1,m):
  for j in range(1,m):
    for k in range(3):
      res[i][j] = max(res[i][j], res[i+dy[k]][j+dx[k]])

for i in range(m):
  print(*res[i])
import sys
input = sys.stdin.readline

n,s,m = map(int,input().split())
volumn = list(map(int,input().split()))
dp = [[False] * (m+1) for i in range(n+1)]
dp[0][s] = True

for i in range(1,n+1):
  for j in range(m+1):
    if dp[i-1][j]:
      if j - volumn[i-1] >= 0:
        dp[i][j-volumn[i-1]] = True
      if j + volumn[i-1] <= m:
        dp[i][j+volumn[i-1]] = True

for i in range(m,-1,-1):
  if dp[n][i]:
    print(i)
    exit()
print(-1)
import sys
input = sys.stdin.readline

# A와 B로 N을 만들고 싶은데 특정 구간에 속하지 않게 만들수 있는가?
# 가장 큰 닫힌구간이 max(a,b)보다 크면 못 건너간다.

n,m,a,b = map(int,input().split())

constrains = []
for i in range(m):
  constrains.append(list(map(int,input().split())))

puppy = [True] * 100001
for i in range(n+1):
  for j in range(m):
    if constrains[j][0] <= i <= constrains[j][1]:
      puppy[i] = False

dp = [123456789] * (n+1)
dp[0] = 0
for i in range(n+1):
  if not puppy[i]:
    continue
  if i - a >= 0 and puppy[i-a]:
    dp[i] = min(dp[i], dp[i-a]+1)
  if i - b >= 0 and puppy[i-b]:
    dp[i] = min(dp[i], dp[i-b]+1)

if dp[n] == 123456789:
  dp[n] = -1
print(dp[n])
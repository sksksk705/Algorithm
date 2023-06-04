import sys
input = sys.stdin.readline

# n길이의 수열을 x개의 구간으로 나눠서, 모든 구간 안에서 최대, 최소 값의 합이 가장 큰 경우를 골라라
n = int(input())

scores = list(map(int, input().split()))

dp = [0] * (n+1)
for i in range(n):
  mx = mn = scores[i]
  for j in range(i,-1,-1):
    mx = max(mx,scores[j])
    mn = min(mn,scores[j])
    dp[i+1] = max(dp[i+1],dp[j]+mx-mn)
    
print(dp[n])
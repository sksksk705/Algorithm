import sys
input = sys.stdin.readline

# n길이의 수열을 x개의 구간으로 나눠서, 모든 구간 안에서 최대, 최소 값의 합이 가장 큰 경우를 골라라
n = int(input())

scores = list(map(int, input().split()))

dp = [0] * (n+1)
for i in range(n-1,-1,-1):
  for j in range(1,n-i+1):
    dp[i] = max(dp[i], max(scores[i:i+j]) - min(scores[i:i+j]) + dp[i+j])
    
print(dp[0])
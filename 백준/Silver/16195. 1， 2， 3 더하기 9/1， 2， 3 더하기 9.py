tc = int(input())
MOD = 1000000009

dp = [[0] * 1001 for _ in range(1001)]
dp[0][0] = 1
dp[1][1] = 1
dp[1][2] = 1
dp[1][3] = 1

for i in range(2, 1000+1):
    for j in range(1, min(1001, i)):
        for k in range(1, 4):
            dp[j+1][i] = dp[j+1][i] + dp[j][i-k]
for t in range(tc):
    n, m = map(int, input().split())
    res = 0
    for i in range(1, m+1):
        res += dp[i][n]
    print(res % MOD)
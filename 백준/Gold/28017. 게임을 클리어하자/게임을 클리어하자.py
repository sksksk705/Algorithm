import sys
input = sys.stdin.readline
INT_MAX = 2 ** 32

n,m = map(int,input().split())

weapons = []
for i in range(n):
    weapons.append(list(map(int,input().split())))

dp = [[INT_MAX]* 501 for _ in range(500)]
def playGame(time, prevUsed):
    if time == n:
        return 0
    if dp[time][prevUsed] != INT_MAX:
        return dp[time][prevUsed]
    for i in range(m):
        if i != prevUsed:
            dp[time][prevUsed] = min(dp[time][prevUsed], playGame(time+1,i) + weapons[time][i])
    return dp[time][prevUsed]
playGame(0,500)
print(dp[0][500])
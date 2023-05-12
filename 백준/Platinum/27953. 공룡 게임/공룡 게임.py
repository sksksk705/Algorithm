import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
MAX_PAN = 1000000000 * 5000 + 1

n, a, b, x, y = map(int, input().split())
obTimes = [-MAX_PAN]
obTypes = [0]

for i in range(n):
    time, type = map(int, input().split())
    obTimes.append(time)
    obTypes.append(type)


dp = [[[MAX_PAN] * (2) for _ in range(n+1)] for _ in range(n+1)]
dp[0][0][0] = 0



#i번째 장애물을 넘었을 때의 패널티값
for i in range(n):
    for j in range(i+1):
        for k in range(2):
            #다음 장애물이 점프로 넘어가야함
            if (obTypes[i + 1] == 1 or obTypes[i + 1] == 3):
                #현재 장애물을 점프로 넘은 상황, 
                if k == 0 and (obTimes[i + 1] - obTimes[i] >= a):
                   dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + x)
                #j번째 장애물을 점프로 넘은 상황
                if k == 1 and (obTimes[i+1] - obTimes[j] >= a):
                    dp[i+1][i][0] = min(dp[i + 1][i][0], dp[i][j][k] + x)
            if (obTypes[i + 1] == 2 or obTypes[i + 1] == 3):
                if k == 1 and (obTimes[i + 1] - obTimes[i] >= b):
                   dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + y)
                if k == 0 and (obTimes[i+1]- obTimes[j] >= b):
                    dp[i+1][i][1] = min(dp[i + 1][i][1], dp[i][j][k] + y)

ans = MAX_PAN
for i in range(n+1):
    ans = min(ans,min(dp[n][i]))
if ans == MAX_PAN:
    ans = -1
print(ans)
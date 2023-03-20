import sys
input = sys.stdin.readline

#x가 세로 y가 가로
def query(x1,y1,x2,y2):
    ans = 0
    for i in range(1,11):
        if(dp[x2][y2][i] - dp[x2][y1-1][i] - dp[x1-1][y2][i] + dp[x1-1][y1-1][i] > 0):
            ans += 1
    return ans

n = int(input())
matrix = [[0] * (n+1)]
for i in range(n):
    matrix.append([0] + list(map(int,input().split())))

dp = [[[0]* 11 for _ in range(n+1)]for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1,n+1):
        for k in range(1,11):
            dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k]
        dp[i][j][matrix[i][j]] += 1

q = int(input())

for i in range(q):
    x1,y1,x2,y2 = map(int,input().split())
    print(query(x1,y1,x2,y2))
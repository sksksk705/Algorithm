import sys
input = sys.stdin.readline
MAX = 30

#n개의 1개
#n개의 반개가 가능하다.
#1개밖에 없는 곳에서는 반개로 쪼개야하고
#반개밖에 없는 곳에서는 먹어야한다.
cache = [[[0]* (MAX+1) for _ in range(MAX+1)] for _ in range(2*MAX + 1)]
cache[0][MAX][0] = 1
for i in range(1,2*MAX+1):
    for j in range(MAX):
        for k in range(MAX+1):
            #오늘 29 1개 = 전날 30 0개
            cache[i][j][k] += cache[i-1][j+1][k-1]

    for j in range(MAX+1):
        for k in range(MAX):
            #오늘 29 0개 = 전날 29 1개
            cache[i][j][k] += cache[i-1][j][k+1]


while(True):
    n = int(input())
    if(n == 0):
        break
    print(cache[2*n][MAX-n][0])
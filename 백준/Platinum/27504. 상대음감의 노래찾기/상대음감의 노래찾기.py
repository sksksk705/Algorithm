#상대음감의 노래찾기
#노래 길이별로 누적합을 구해 누적합이 같은 경우에만 비교를 진행하면 빠르게 할 수 있을듯?

import sys
input = sys.stdin.readline
n = int(input())
songs = []

for i in range(n):
    songs.append(list(map(int,input().split())))

l = int(input())
melody = list(map(int,input().split()))
presum = 0
for i in range(l):
    presum += melody[i] - melody[0]

res = []
for i in range(n):
    prefix = []
    for j in range(0, len(songs[i]) - l+1):
        isFind = False
        if(j == 0):
            prefixsum = 0;
            for k in range(l):
                prefixsum += songs[i][k] - songs[i][0]
            prefix.append(prefixsum)
        else:
            prefix.append(prefix[-1] + songs[i][j-1]*(l-1) + songs[i][j+l-1] - songs[i][j]*l)
        if(prefix[-1] == presum):
            diff = songs[i][j] - melody[0]
            for k in range(1,l):
                if(songs[i][j+k] - melody[k] != diff):
                    break
            if(k == l-1):
                isFind = True
        if(isFind):
            res.append(i+1)
            break
if(len(res) == 0):
    print(-1)
else:
    print(*res)
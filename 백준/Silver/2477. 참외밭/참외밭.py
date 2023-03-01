import sys
input = sys.stdin.readline
#큰 직사각형에서 작은 직사각형을 빼주면 된다.

k = int(input())

ground = []

maxr, maxc =0,0
for i in range(6):
    dir,length = map(int,input().split())
    if(dir == 1 or dir == 2):
        maxc = max(maxc, length)
    if(dir == 3 or dir == 4):
        maxr = max(maxr, length)
    ground.append([dir,length])

res = maxr * maxc
for i in range(6):
    if(ground[(i+2)%6][0] == ground[i][0] and ground[(i+1)%6][0] == ground[(i+3)%6][0]): 
      res -= ground[(i+2)%6][1] * ground[(i+1)%6][1] 
      break

print(res*k)
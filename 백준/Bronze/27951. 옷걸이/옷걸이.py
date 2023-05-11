import sys
input = sys.stdin.readline

n = int(input())
hangers = list(map(int,input().split()))
top, bottom = map(int,input().split())

topCnt = 0
bottomCnt = 0
for i in range(n):
    if hangers[i] == 1:
        topCnt += 1
    elif hangers[i] == 2:
        bottomCnt += 1

if topCnt > top or bottomCnt > bottom:
    print("NO")
    exit()

topRemain = top - topCnt

print("YES")
for i in range(n):
    if hangers[i] == 1:
        print("U",end="")
    elif hangers[i] == 2:
        print("D",end="")
    else:
        if topRemain:
            topRemain -= 1
            print("U", end="")
        else:
            print("D", end="")
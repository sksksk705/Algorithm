import math
n,m,k = map(int,input().split())

maxRes = int(math.log2(n))
win = int(math.log2(k))

print(min(win+m,maxRes))
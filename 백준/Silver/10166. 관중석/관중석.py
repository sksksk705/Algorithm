from math import gcd
from sys import stdin

d1,d2 = map(int,stdin.readline().split())
arr = [[0]* d2 for _ in range(d2)]

ans = 0
for i in range(d1,d2+1):
    for j in range(1,i+1):
        g = gcd(i,j)
        if not arr[i//g-1][j//g-1]:
            arr[i//g-1][j//g-1] = 1
            ans += 1
print(ans)
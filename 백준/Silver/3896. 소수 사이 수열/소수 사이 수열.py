import math
import sys
input = sys.stdin.readline
MAX = 1299710

isPrime = [True] * MAX
for i in range(2,int(math.sqrt(MAX))):
    if isPrime[i]:
        for j in range(i+i,MAX,i):
            isPrime[j] = False


t = int(input())
for i in range(t):
    k = int(input())
    if isPrime[k]:
        print(0)
        continue
    cnt = 1
    for i in range(k,2,-1):
        if isPrime[i]:
            break
        cnt += 1
    for i in range(k+1,MAX):
        if isPrime[i]:
            break
        cnt += 1
    print(cnt)
import math
import sys
input = sys.stdin.readline

n,k = map(int,input().split())

#왼쪽이 더 크면 오른쪽 사람과 그렇고 그런 사이

max = n
num = 1



for i in range(1, n+1): 
    if n - i <= k:
        print(max,end = ' ')
        max -= 1
        k -= (n-i)
    else:
        print(num, end = ' ')
        num += 1
import sys
input = sys.stdin.readline

n = int(input())
lst = list(map(int,input().split()))

ans = 501
for i in range(n-1):
    for j in range(i+1,n):
        d = (lst[j] - lst[i]) // (j - i)
        needChange = 0
        for k in range(0,n):
            if lst[i] + (k - i) * d != lst[k]:
                needChange += 1
        ans = min(ans,needChange)


print(ans)
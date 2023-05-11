import sys
input = sys.stdin.readline

n,x = map(int,input().split())

limits = list(map(int,input().split()))
growth = list(map(int,input().split()))

weight = 0
for i in range(n):
    weight += growth[i]
    if weight < limits[i]:
        print(-1)
        exit()

print(int((weight - limits[-1])/x))
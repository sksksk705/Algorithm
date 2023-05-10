import sys
input = sys.stdin.readline

n,m = map(int,input().split())

prev = [0] * m
for day in range(n):
    weapons = list(map(int,input().split()))
    minWeaponIdx = min(range(m),key=prev.__getitem__)
    prev.sort()
    for i in range(m):
        if i == minWeaponIdx:
            weapons[i] += prev[1]
        else:
            weapons[i] += prev[0]
    prev = weapons

print(min(prev))
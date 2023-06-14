import sys
input = sys.stdin.readline

n = int(input())
d = {}
d['ChongChong'] = 1

for i in range(n):
    p1, p2 = input().strip().split(' ')
    if p1 not in d:
        d[p1] = 0
    if p2 not in d:
        d[p2] = 0
    if d[p1] == 1 or d[p2] == 1:
        d[p1] = 1
        d[p2] = 1

print(sum(d.values()))
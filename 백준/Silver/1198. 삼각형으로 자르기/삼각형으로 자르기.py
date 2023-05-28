import sys
import itertools
input = sys.stdin.readline


def calc(x1, y1, x2, y2, x3, y3):
    return abs(x1 * y2 + x2*y3 + x3*y1 - (x2*y1+x3*y2+x1*y3))


n = int(input())
point = []
for i in range(n):
    point.append(list(map(int, input().split())))

comb = list(itertools.combinations([i for i in range(n)], 3))

res = 0
for combined in comb:
    res = max(res, calc(
        point[combined[0]][0],
        point[combined[0]][1],
        point[combined[1]][0],
        point[combined[1]][1],
        point[combined[2]][0],
        point[combined[2]][1]
    ))

print(res/2)
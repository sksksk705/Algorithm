import sys
input = sys.stdin.readline

c,r = map(int,input().split())
n = int(input())

stores = []

for i in range(n):
    pos, dist = map(int,input().split())
    if pos == 1:
        stores.append((0,dist))
    elif pos == 2:
        stores.append((r, dist))
    elif pos == 3:
        stores.append((dist, 0))
    elif pos == 4:
        stores.append((dist, c))

pos,dist = map(int,input().split())
if pos == 1:
    mx = dist; my = 0
elif pos == 2:
    mx = dist; my = r
    stores.append((r, dist))
elif pos == 3:
    mx = 0; my = dist
    stores.append((dist, 0))
elif pos == 4:
    mx = c; my = dist
    stores.append((dist, c))


def calc_dist(sx,sy,ex,ey):
    global r,c
    # 두개가 맞은 편에 있을 경우
    if abs(sx-ex) == c or abs(sy - ey) == r:
        # 둘 다 세로에 있을 때
        if sx == 0 or sx == c:
            res = min(sy+ey, r - sy + r - ey)
            res += c
        # 둘 다 가로에 있을 때
        else:
            res = min(sx+ex, c - sx + c - ex)
            res += r
    else:
        res = abs(sx-ex) + abs(sy-ey)
    return res

ans = 0
for i in range(n):
    dist = calc_dist(mx,my,stores[i][1],stores[i][0])
    ans += dist

print(ans)
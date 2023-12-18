import sys
input = sys.stdin.readline

x,y,w,s = map(int,input().split())

if w * 2 < s:
    print((x+y)*w)
else:
    res = 0
    smaller = min (x,y)
    res += smaller*s

    remain = (x+y - 2 * smaller)

    if s < w:
        moves = s
    else:
        moves = w

    res += int(remain /2) * moves*2 + remain%2 * w 
    print(res)
import sys
input = sys.stdin.readline

c = int(input())

for tc in range(c):
    n, l1, l2, s1, s2 = map(int, input().split())
    onePass = list(map(int, input().split()))
    oneDribble = list(map(int, input().split()))
    twoPass = list(map(int, input().split()))
    twoDribble = list(map(int, input().split()))

    cache = [[0, 0] for _ in range(n)]

    cache[0][0] = l1
    cache[0][1] = l2

    for i in range(n-1):
        cache[i+1][0] = min(cache[i][0] + oneDribble[i],
                            cache[i][1] + twoPass[i])
        cache[i+1][1] = min(cache[i][1] + twoDribble[i],
                            cache[i][0] + onePass[i])
    print(min(cache[n-1][0] + s1, cache[n-1][1] + s2))
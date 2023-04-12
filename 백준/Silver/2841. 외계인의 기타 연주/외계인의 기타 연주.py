# 6개의 줄 p개의 프렛 (1 ~ p)
# 줄 번호 + 프렛 번호
# 가장 적게 누르는 경우의 수
# 웬만하면 안 떼는게 좋지 않을까? (stack 자료구조에 넣어서 작은 게 나오기 전까지 pop)


import sys
input = sys.stdin.readline

n,p = map(int,input().split())

guitar = [[] for _ in range(7)]

cnt = 0
for i in range(n):
    line,plat = map(int,input().split())
    while guitar[line] and guitar[line][-1] > plat:
        guitar[line].pop()
        cnt += 1
    if guitar[line] and guitar[line][-1] == plat:
        continue
    guitar[line].append(plat)
    cnt += 1
print(cnt)
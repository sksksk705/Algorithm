# 색종이 붙이기
# 탐색을 하다 1이 나오면 5부터 붙이기 시작해 맞는 걸 붙여준다.
# 붙이는 과정에서 0이 존재하면 돌아온다
# 만약 붙여야하는데 모든 색종이가 다 떨어졌다면 -1
import copy
import sys
from collections import deque

input = sys.stdin.readline


def attach(x,y,size):
    changed = []
    for i in range(size):
        for j in range(size):
            if paper[y+i][x+j] == 0:
                return []
            changed.append((y+i, x+j))
    return changed

def findOne(ori_paper):
    for i in range(10):
        for j in range(10):
            # 1이면 붙혀줘야한다.
            if ori_paper[i][j] == 1:
                return [i,j]
    return []


def dfs():
    global ans
    if sum(color) > ans:
        return
    one_pos = findOne(paper)
    if not one_pos:
        ans = sum(color)
        return
    [y,x] = one_pos
    for size in range(5, 0, -1):
        # 붙힐 종이가 없거나, 붙혔을 때 범위를 넘어가면 안 됨
        if color[size - 1] >= 5 or x + size > 10 or y + size > 10:
            continue
        attached = attach(x, y, size)
        if attached:
            for [oney,onex] in attached:
                paper[oney][onex] = 0
            color[size-1] += 1
            dfs()
            color[size-1] -= 1
            for [oney,onex] in attached:
                paper[oney][onex] = 1



color = [0,0,0,0,0]
paper = []
for i in range(10):
    paper.append(list(map(int,input().split())))

ans = 30
dfs()
if ans == 30:
    ans = -1
print(ans)
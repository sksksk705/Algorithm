# 사다리조작
# 사다리 결과를 구하고 정렬되어있지 않다면 비어있는 위치에 사다리를 놔보고 결과값을 확인
# 3개까지 탐색하다가 없으면 break

# 구현해야하는 내용
# 1. 사다리를 타고 내려가는 결과를 구하는 함수
# 2. 비어있는 사다리를 구하는 것
# 3. 사다리를 개수만큼 선택해서 추가해주는 것

import sys


def canPut(i,j,ladder):
    return not ladder[i][j-1] and not ladder[i][j+1] and not ladder[i][j]

def getLadderResult(ladder):
    global n,h
    result = [0 for _ in range(n+2)]
    for j in range(1,n+1):
        start = j
        for i in range(1,h+1):
            if(ladder[i][start]):
                start +=1
            elif(ladder[i][start-1]):
                start -=1
        result[start] = j
    result.pop(0)
    result.pop()
    return result

def ladderGame(ladder):
    global n,m,h
    for depth in range(4):
        if(dfs(ladder,depth,0,emptyLadder,-1)):
            return depth
    return -1

def dfs(ladder,limit, depth,emptyLadder, idx):
    if(depth == limit):
        if(getLadderResult(ladder) == result):
            return True
        return False
    for i in range(idx+1, len(emptyLadder)):
        (y,x) = emptyLadder[i]
        if(canPut(y,x,ladder)):
            ladder[y][x] = 1
            if(dfs(ladder,limit,depth+1,emptyLadder,i)):
                return True
            ladder[y][x] = 0
    return False


n,m,h = map(int,sys.stdin.readline().split())
ladder = [[0 for _ in range(n+2)] for _ in range(h+1)]
result = [i for i in range(1,n+1)]
for i in range(m):
    a,b = map(int,sys.stdin.readline().split())
    ladder[a][b] = 1

emptyLadder = []
for i in range(1,h+1):
    for j in range(1,n+1):
        if(canPut(i,j,ladder)):
            emptyLadder.append((i,j))

res = ladderGame(ladder)
print(res)
#구현해야하는 것들
#1. 낚시왕의 이동 및 상어 잡는 로직
#   오른쪽 끝을 넘어가면 로직 종료
#   상어 크기를 결과값에 더해주고 해당 상어 삭제
#2. 상어의 이동
#   속도만큼 이동 및 방향 반대로 전환
#   이동 후 같은 자리에 있는 상어중 가장 큰 상어만 남기고 삭제

import copy
import sys

class Shark:
    def __init__(self, r,c,s,d,z):
        self.r = r
        self.c = c
        self.s = s
        self.d = d
        self.z = z

dx = [0,0,0,1,-1]
dy = [0,-1,1,0,0]
def fishking():
    global kx,R,res
    #오른쪽으로 이동
    for i in range(1, R+1):
        #가장 높은 위치에 있는 상어의 크기를 결과값에 더해준다
        #그리고 해당 상어를 삭제하고 지도에서도 지워준다
        sharkIdx = sharkMap[i][kx]
        if(sharkIdx != -1):
            res += shark[sharkIdx].z
            shark[sharkIdx] = None
            sharkMap[i][kx] = -1
            return

#이동해서 새로운 지도에 추가하고 만약 그 위치에 상어가 있다면 큰 상어만 남기고 삭제한다.
def moveShark(idx ,newSharkMap):
    global R,C
    sharkToMove = shark[idx]
    #s = n과 s = n + (r-1)*2는 같다
    if(sharkToMove.d < 3):
        for i in range(sharkToMove.s % ((R-1)*2)):
            ny = sharkToMove.r + dy[sharkToMove.d]
            if(ny < 1):
                sharkToMove.r = 2
                sharkToMove.d = 2
            elif(ny > R):
                sharkToMove.r = R-1
                sharkToMove.d = 1
            else:
                sharkToMove.r = ny
    else:
         for i in range(sharkToMove.s % ((C-1)*2)):
            nx = sharkToMove.c + dx[sharkToMove.d]
            if(nx < 1):
                sharkToMove.c = 2
                sharkToMove.d = 3
            elif(nx > C):
                sharkToMove.c = C-1
                sharkToMove.d = 4
            else:
                sharkToMove.c = nx
    sharkIdx = newSharkMap[sharkToMove.r][sharkToMove.c]
    if(sharkIdx != -1):
        if(shark[sharkIdx].z > shark[idx].z):
            shark[idx] = None
        else:
            shark[sharkIdx] = None
            newSharkMap[sharkToMove.r][sharkToMove.c] = idx
    else:
        newSharkMap[sharkToMove.r][sharkToMove.c] = idx

kx = 0; res = 0
R,C,m = map(int,sys.stdin.readline().split())
#상어의 정보를 저장할 배열
shark = []
#상어의 위치를 나타낼 지도(해당 위치에 인덱스로)
sharkMap = [[-1 for _ in range(C+1)] for _ in range(R+1)]
#상어의 정보를 받아서 상어정보 배열과 지도에 반영
for i in range(m):
    r,c,s,d,z = map(int,sys.stdin.readline().split())
    shark.append(Shark(r,c,s,d,z))
    sharkMap[r][c] = i

while(kx < C):
    kx += 1
    fishking()
    newSharkMap = [[-1 for _ in range(C+1)] for _ in range(R+1)]
    for i in range(m):
        if(shark[i]):
            moveShark(i,newSharkMap)
    sharkMap = copy.deepcopy(newSharkMap)

print(res)
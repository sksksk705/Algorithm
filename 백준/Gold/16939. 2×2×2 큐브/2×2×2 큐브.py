# 2x2x2 큐브
# 한번 돌리는 방법은 6가지
# 위 왼오/아래 왼/왼 위/오 위/앞 시/뒤 시
import sys
import copy
# 0: 위, 1: 정면, 2: 아래, 3: 왼쪽, 4: 오른쪽 ,5: 뒤
def leftTop(cube):
    myCube= copy.deepcopy(cube)
    temp = myCube[0][:]
    #정 -> 위
    myCube[0][0] = myCube[1][0]
    myCube[0][2] = myCube[1][2]
    #아래 -> 정
    myCube[1][0] = myCube[2][0]
    myCube[1][2] = myCube[2][2]
    #뒤 -> 이레
    myCube[2][0] = myCube[5][1]
    myCube[2][2] = myCube[5][3]
    #위 -> 뒤
    myCube[5][1] = temp[0]
    myCube[5][3] = temp[2]
    return myCube
def RightTop(cube):
    myCube= copy.deepcopy(cube)
    temp = myCube[0][:]
    #정 -> 위
    myCube[0][1] = myCube[1][1]
    myCube[0][3] = myCube[1][3]
    #아래 -> 정
    myCube[1][1] = myCube[2][1]
    myCube[1][3] = myCube[2][3]
    #뒤 -> 이레
    myCube[2][1] = myCube[5][0]
    myCube[2][3] = myCube[5][2]
    #위 -> 뒤
    myCube[5][0] = temp[1]
    myCube[5][2] = temp[3]
    return myCube
    myCube= copy.deepcopy(cube)
    #위가 임시
    temp = myCube[0][:]
    #뒤 -> 위
    myCube[0][1] = myCube[5][1]
    myCube[0][3] = myCube[5][3]
    #아래 -> 뒤
    myCube[5][1] = myCube[2][1]
    myCube[5][3] = myCube[2][3]
    #정 -> 아래
    myCube[2][1] = myCube[1][0]
    myCube[2][3] = myCube[1][2]
    #위 -> 정
    myCube[1][0] = temp[1]
    myCube[1][2] = temp[3]
    return myCube
def topLeft(cube):
    myCube= copy.deepcopy(cube)
    #정이 임시
    temp = myCube[1][:]
    #오 -> 정
    myCube[1][0] = myCube[4][0]
    myCube[1][1] = myCube[4][1]
    #뒤 -> 오
    myCube[4][0] = myCube[5][0]
    myCube[4][1] = myCube[5][1]
    #완 -> 뒤
    myCube[5][0] = myCube[3][0]
    myCube[5][1] = myCube[3][1]
    #정 -> 왼
    myCube[3][0] = temp[0]
    myCube[3][1] = temp[1]
    return myCube
def BottomLeft(cube):
    myCube= copy.deepcopy(cube)
    #정이 임시
    temp = myCube[1][:]
    #오 -> 정
    myCube[1][2] = myCube[4][2]
    myCube[1][3] = myCube[4][3]
    #뒤 -> 오
    myCube[4][2] = myCube[5][2]
    myCube[4][3] = myCube[5][3]
    #완 -> 뒤
    myCube[5][2] = myCube[3][2]
    myCube[5][3] = myCube[3][3]
    #정 -> 왼
    myCube[3][2] = temp[2]
    myCube[3][3] = temp[3]
    return myCube
    myCube= copy.deepcopy(cube)
    temp = myCube[1][:]
    #왼 -> 정
    myCube[1][2] = myCube[3][2]
    myCube[1][3] = myCube[3][3]
    #뒤 -> 왼
    myCube[3][2] = myCube[5][2]
    myCube[3][3] = myCube[5][3]
    #오 -> 뒤
    myCube[5][2] = myCube[4][2]
    myCube[5][3] = myCube[4][3]
    #정 -> 오
    myCube[4][2] = temp[2]
    myCube[4][3] = temp[3]
    return myCube
def frontRight(cube):
    myCube= copy.deepcopy(cube)
    temp = myCube[0][:]
    #왼 -> 위
    myCube[0][2] = myCube[3][1]
    myCube[0][3] = myCube[3][3]
    #아래 -> 왼
    myCube[3][1] = myCube[2][0]
    myCube[3][3] = myCube[2][1]
    #오 -> 아래
    myCube[2][0] = myCube[4][0]
    myCube[2][1] = myCube[4][2]
    #위 -> 오
    myCube[4][0] = temp[2]
    myCube[4][2] = temp[3]
    return myCube
def BackRight(cube):
    myCube= copy.deepcopy(cube)
    temp = myCube[0][:]
    #왼 -> 위
    myCube[0][0] = myCube[3][0]
    myCube[0][1] = myCube[3][2]
    #아래 -> 왼
    myCube[3][0] = myCube[2][2]
    myCube[3][2] = myCube[2][3]
    #오 -> 아래
    myCube[2][2] = myCube[4][1]
    myCube[2][3] = myCube[4][3]
    #위 -> 오
    myCube[4][1] = temp[0]
    myCube[4][3] = temp[1]
    return myCube
    myCube= copy.deepcopy(cube)

    #위가 임시
    temp = myCube[0][:]
    #오 -> 위
    myCube[0][0] = myCube[4][1]
    myCube[0][1] = myCube[4][3]
    #아래 -> 오
    myCube[4][1] = myCube[2][2]
    myCube[4][3] = myCube[2][3]
    #왼 -> 아래
    myCube[2][2] = myCube[3][0]
    myCube[2][3] = myCube[3][2]
    #위 -> 왼
    myCube[3][0] = temp[0]
    myCube[3][2] = temp[1]
    return myCube
def isMatch(cube):
    for i in range(6):
        color = 3
        for j in range(1,4):
            if(cube[i][0] == cube[i][j]):
                color -= 1
        if(color > 0):
            return False
    return True

cube = [[] for _ in range(6)]

ip = list(map(int,sys.stdin.readline().split()))
for i in range(6):
    for j in range(4):
        cube[i].append(ip[i*4+j])

cubeFunc = [leftTop,RightTop,topLeft,BottomLeft,frontRight, BackRight]

isBreak = False
for i in range(6):
    if(isMatch(cubeFunc[i](cube))):
        print(1)
        isBreak = True
        break

if(not isBreak):
    print(0)
# 5373번 큐빙
# 큐브가 맞춰진 상태에서 시작하여 큐브를 n번 돌렸을 때의 윗면을 출력하는 문제
# 6개의 면, 3x3 개의 블럭
# 6개의 면에 대해 2가지 방향으로 움직일 수 있기 때문에 12개의 함수를 만들어줘야함

import copy
import sys
input = sys.stdin.readline

#pos: 0,1,2,3,4,5 (면) dir: 0,1 (시계,반시계)
def Rotation(pos, dir):
    newPos = [[0,0,0],[0,0,0],[0,0,0]]
    if(dir == 0):
        for i in range(3):
            for j in range(3):
                newPos[i][j] = cube[pos][2 - j][i]
    else:
        for i in range(3):
            for j in range(3):
                newPos[i][j] = cube[pos][j][2-i]
    cube[pos] = newPos

def topClock():
    Rotation(0,0)
    temp = copy.deepcopy(cube[2][0])
    #앞 = 오
    cube[2][0] = copy.deepcopy(cube[5][0])
    #오 = 뒤
    cube[5][0] = [cube[3][2][2],cube[3][2][1],cube[3][2][0]]
    #뒤 = 왼
    [cube[3][2][2],cube[3][2][1],cube[3][2][0]] = copy.deepcopy(cube[4][0])
    #왼 = 앞
    cube[4][0] = temp


def bottomClock():
    Rotation(1,0)
    temp = copy.deepcopy(cube[2][2])
    #앞 = 왼
    cube[2][2] = copy.deepcopy(cube[4][2])
    #왼 = 뒤
    cube[4][2] = [cube[3][0][2],cube[3][0][1],cube[3][0][0]]
    #뒤 = 오
    [cube[3][0][2],cube[3][0][1],cube[3][0][0]] = copy.deepcopy(cube[5][2])
    #오 = 앞
    cube[5][2] = copy.deepcopy(temp)

def frontClock():
    Rotation(2,0)
    temp = copy.deepcopy(cube[0][2])
    #위 = 왼
    cube[0][2] = [cube[4][2][2],cube[4][1][2],cube[4][0][2]]
    #왼 = 밑
    [cube[4][0][2],cube[4][1][2],cube[4][2][2]] = copy.deepcopy(cube[1][0])
    #밑 = 오
    cube[1][0] = [cube[5][2][0],cube[5][1][0],cube[5][0][0]]
    #오 = 위
    [cube[5][0][0],cube[5][1][0],cube[5][2][0]] = temp

def backClock():
    Rotation(3,0)
    temp = copy.deepcopy(cube[0][0])
    #위 = 오
    cube[0][0] = [cube[5][0][2],cube[5][1][2],cube[5][2][2]]
    #오 = 밑
    [cube[5][2][2],cube[5][1][2],cube[5][0][2]] = copy.deepcopy(cube[1][2])
    #밑 = 왼
    cube[1][2] = [cube[4][0][0],cube[4][1][0],cube[4][2][0]]
    #왼 = 위
    [cube[4][2][0],cube[4][1][0],cube[4][0][0]] = temp


def leftClock():
    Rotation(4,0)
    temp = [cube[0][0][0],cube[0][1][0], cube[0][2][0]]
    #위 = 뒤
    [cube[0][0][0],cube[0][1][0], cube[0][2][0]] = [cube[3][0][0],cube[3][1][0],cube[3][2][0]]
    #뒤 = 밑
    [cube[3][0][0],cube[3][1][0],cube[3][2][0]] = [cube[1][0][0],cube[1][1][0],cube[1][2][0]]
    #밑 = 앞
    [cube[1][0][0],cube[1][1][0],cube[1][2][0]] =  [cube[2][0][0],cube[2][1][0],cube[2][2][0]]
    #잎 = 위
    [cube[2][0][0],cube[2][1][0],cube[2][2][0]] = temp

def rightClock():
    Rotation(5,0)
    temp = [cube[0][0][2],cube[0][1][2], cube[0][2][2]]
    #위 = 앞
    [cube[0][0][2],cube[0][1][2], cube[0][2][2]] = [cube[2][0][2],cube[2][1][2],cube[2][2][2]]
    #앞 = 밑
    [cube[2][0][2],cube[2][1][2],cube[2][2][2]] =  [cube[1][0][2],cube[1][1][2],cube[1][2][2]]
    #밑 = 뒤
    [cube[1][0][2],cube[1][1][2],cube[1][2][2]] =  [cube[3][0][2],cube[3][1][2],cube[3][2][2]]
    #뒤 = 위
    [cube[3][0][2],cube[3][1][2],cube[3][2][2]] = temp

def topReverse():
    Rotation(0,1)
    temp = copy.deepcopy(cube[2][0])
    #앞 = 왼
    cube[2][0] = copy.deepcopy(cube[4][0])
    #왼 = 뒤
    cube[4][0] = [cube[3][2][2],cube[3][2][1],cube[3][2][0]]
    #뒤 = 오
    [cube[3][2][2],cube[3][2][1],cube[3][2][0]] =  copy.deepcopy(cube[5][0])  
    #오 = 앞
    cube[5][0] = temp

def bottomReverse():
    Rotation(1,1)
    temp = copy.deepcopy(cube[2][2])
    #앞 = 오
    cube[2][2] = copy.deepcopy(cube[5][2])
    #오 = 뒤
    cube[5][2] = [cube[3][0][2],cube[3][0][1],cube[3][0][0]]
    #뒤 = 왼
    [cube[3][0][2],cube[3][0][1],cube[3][0][0]] = copy.deepcopy(cube[4][2])  
    #왼 = 앞
    cube[4][2] = temp

def frontReverse():
    Rotation(2,1)
    temp = copy.deepcopy(cube[0][2])
    #위 = 오
    cube[0][2] = [cube[5][0][0],cube[5][1][0],cube[5][2][0]]
    #오 = 밑
    [cube[5][2][0],cube[5][1][0],cube[5][0][0]] = copy.deepcopy(cube[1][0])
    #밑 = 왼
    cube[1][0] = [cube[4][0][2],cube[4][1][2],cube[4][2][2]] 
    #왼 = 위
    [cube[4][2][2],cube[4][1][2],cube[4][0][2]]  = temp

def backReverse():
    Rotation(3,1)
    temp = copy.deepcopy(cube[0][0])
    #위 = 왼
    cube[0][0] = [cube[4][2][0],cube[4][1][0],cube[4][0][0]] 
    #왼 = 밑
    [cube[4][0][0],cube[4][1][0],cube[4][2][0]]  = copy.deepcopy(cube[1][2])
    #밑 = 오
    cube[1][2] = [cube[5][2][2],cube[5][1][2],cube[5][0][2]] 
    #오 = 위
    [cube[5][0][2],cube[5][1][2],cube[5][2][2]]  = temp

def leftReverse():
    Rotation(4,1)
    temp = [cube[0][0][0],cube[0][1][0], cube[0][2][0]]
    #위 = 앞
    [cube[0][0][0],cube[0][1][0], cube[0][2][0]] = [cube[2][0][0],cube[2][1][0],cube[2][2][0]] 
    #앞 = 밑
    [cube[2][0][0],cube[2][1][0],cube[2][2][0]]  = [cube[1][0][0],cube[1][1][0],cube[1][2][0]]
    #밑 = 뒤
    [cube[1][0][0],cube[1][1][0],cube[1][2][0]] = [cube[3][0][0],cube[3][1][0],cube[3][2][0]]
    #뒤 = 위
    [cube[3][0][0],cube[3][1][0],cube[3][2][0]]= temp

def rightReverse():
    Rotation(5,1)
    temp = [cube[0][0][2],cube[0][1][2], cube[0][2][2]]
    #위 = 뒤
    [cube[0][0][2],cube[0][1][2], cube[0][2][2]] = [cube[3][0][2],cube[3][1][2],cube[3][2][2]]
    #뒤 = 밑
    [cube[3][0][2],cube[3][1][2],cube[3][2][2]] = [cube[1][0][2],cube[1][1][2],cube[1][2][2]]
    #밑 = 앞
    [cube[1][0][2],cube[1][1][2],cube[1][2][2]] =  [cube[2][0][2],cube[2][1][2],cube[2][2][2]]
    #앞 = 위
    [cube[2][0][2],cube[2][1][2],cube[2][2][2]] = temp

def makeCube():
    cube = [
    #위
    [['w','w','w'],['w','w','w'],['w','w','w']],
    #아래
    [['y','y','y'],['y','y','y'],['y','y','y']],
    #앞
    [['r','r','r'],['r','r','r'],['r','r','r']],
    #뒤
    [['o','o','o'],['o','o','o'],['o','o','o']],
    #왼
    [['g','g','g'],['g','g','g'],['g','g','g']],
    #오
    [['b','b','b'],['b','b','b'],['b','b','b']]]
    return cube


t = int(input())
for _ in range(t):
    n = int(input())
    cube = makeCube();
    op_list = list(input().rstrip().split(' '))
    for op in op_list:
        if(op =='U-'):
            topReverse();
        elif(op =='U+'):
            topClock();
        elif(op =='D-'):
            bottomReverse();
        elif(op =='D+'):
            bottomClock();
        elif(op =='F-'):
            frontReverse();
        elif(op =='F+'):
            frontClock();
        elif(op =='B-'):
            backReverse();
        elif(op =='B+'):
            backClock();
        elif(op =='L-'):
            leftReverse();
        elif(op =='L+'):
            leftClock();
        elif(op =='R-'):
            rightReverse();
        elif(op =='R+'):
            rightClock();
        a = 0
    for i in range(3):
        print(''.join(cube[0][i]))
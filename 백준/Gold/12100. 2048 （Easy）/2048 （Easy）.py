from collections import deque
import copy
import sys
input = sys.stdin.readline
#12100번 2048

# 구현해야하는 내용 
# 1. 블록을 움직이며 보드를 변화시키는 함수
#    - 움직이려는 방향에서 가까운 쪽부터 움직임
#    - 자신과 같은 숫자를 만나면 합치고 움직일 수 없을 때까지 이동 
# 2. bfs로 5번 4가지 방향으로 움직이는 방법

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def calcBest(board):
    global n
    best  = 0
    for i in range(n):
        for j in range(n):
            if(board[i][j] > best):
                best = board[i][j]
    return best

def canMove(px,py,x,y,board):
    global n
    #범위를 초과했거나 나보다 높은 블럭이 이동하려는 방향에 있으면 못 움직임
    #                 *빈공간이 아니면서 나와 같지 않으면 못 움직임
    return not(x < 0 or x >=n or y < 0 or y >= n or (board[y][x] != 0 and board[py][px] != board[y][x]))

def move(x,y,dir,board,haveMerged):
    nx = x + dx[dir]
    ny = y + dy[dir]
    isMerged = False
    while(canMove(x,y,nx,ny,board)):
        #만약 움직이려는 곳의 숫자가 나와같다면 합쳐줌
        #*이미 합쳐진 곳이라면 더이상 합쳐질 수 없다!
        if(board[ny][nx] == board[y][x]):
            if((nx,ny) in haveMerged or isMerged):
                break
            board[ny][nx] *= 2
            board[y][x] = 0
            isMerged = True
        #움직이려는 곳이 빈곳이면 움직임
        else:
            board[ny][nx] = board[y][x]
            board[y][x] = 0

        y = ny
        ny = y + dy[dir]

        x = nx
        nx = x + dx[dir]
    if(isMerged):
      haveMerged[(x,y)] = 0
    

def moveBoard(board,dir):
    #원래 보드를 해치치 않는 상태를 유지
    newBoard = copy.deepcopy(board)
    haveMerged = {}
    global n
    for i in range(n):
        for j in range(n):
          if(dir == 0):
              #왼쪽블럭 우선
              main = j
              cross = i
          elif(dir == 1):
              #오른쪽 블럭 우선
              main = j
              cross = n - 1 - i
          elif(dir == 2):
              #위쪽블럭 우선
              main = i
              cross = j
          elif(dir == 3):
              #아래쪽 블럭 우선
              main = n - 1 - i
              cross = j
          #움직이려는 위치에 블럭이 존재할 경우 움직여줌
          if(newBoard[main][cross] != 0):
            move(cross,main,dir,newBoard,haveMerged)
    return newBoard


def bfs():
    myBoard = copy.deepcopy(board)
    q = deque()
    q.append((myBoard,0))
    best = 0
    while(q):
        (nowBoard,t) = q.popleft()
        if(t == 5):
            #5번 움직였을 때의 최대값을 구해줌  
            best = max(calcBest(nowBoard),best)
            continue
        for i in range(4):
            #4가지 방향으로 움직일 수 있음
            newBoard = moveBoard(nowBoard,i)
            q.append((newBoard,t+1))
    return best

n = int(input())
board = []
for i in range(n):
    board.append(list(map(int,input().split())))

res = bfs()
print(res)
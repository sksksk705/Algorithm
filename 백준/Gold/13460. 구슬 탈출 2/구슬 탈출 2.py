#구슬탈출 2
# 중력을 이요해서 왼쪽,오른쪽,위쪽,아래쪽으로 기울이기 4가지 동작이 가능하다
# 공은 동시에 움직인다. 빨간 구슬이 빠지면 성공, 파란구슬이 빠지면 실패, 동시도 실패
# 더 이상 구슬이 움직이지 않을 때까지 움직인다.
# 몇번 만에 빨간 구슬을 꺼낼 수 있을까?
# 10번 이상이면 -1 (뎁스를 10까지만), 한 뎁스당 4개 => 4**10

#구현해야하는 내용
# 1. 움직이는 함수
#   방향에 따라 그 쪽에 있는 구슬이 먼저 움직여야함
#   redx,redy,bluex,bluey,dir
#   반환값: 성공시 1 실패시 -1, 움직일 시 0
import sys
from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]
def moveMarble(redx,redy,bluex,bluey,dir):
    #방향에 따라 움직일 순서가 다르다.
    #왼쪽으로 움직인다면 x가 작은게 먼저 움직인다.
    if(dir == 0):
        if(redx < bluex):
            fx,fy,sx,sy = redx,redy,bluex,bluey
            f,s= 0,1
        else:
            fx,fy,sx,sy = bluex,bluey,redx,redy
            f,s= 1,0
    #오른쪽으로 움직인다면 x가 큰게 먼저 움직인다.
    elif(dir == 1):
        if(redx > bluex):
            fx,fy,sx,sy = redx,redy,bluex,bluey
            f,s= 0,1
        else:
            fx,fy,sx,sy = bluex,bluey,redx,redy
            f,s= 1,0
    #위로 움직인다면 y가 작은게 먼저 움직인다.
    elif(dir == 2):
        if(redy < bluey):
            fx,fy,sx,sy = redx,redy,bluex,bluey
            f,s= 0,1
        else:
            fx,fy,sx,sy = bluex,bluey,redx,redy
            f,s= 1,0
    #아래으로 움직인다면 y가 큰게 먼저 움직인다.
    else:
        if(redy > bluey):
            fx,fy,sx,sy = redx,redy,bluex,bluey
            f,s= 0,1
        else:
            fx,fy,sx,sy = bluex,bluey,redx,redy
            f,s= 1,0
    
    firstIn = False;
    secondIn = False;

    #두 구슬을 움직여 준다
    while(True):
        fnx,fny = fx + dx[dir],fy + dy[dir]
        #들어갔으니까 사실상 없애줌
        if(board[fny][fnx] == 'O'):
            firstIn = True
            fx,fy = 0,0
            break
        elif(board[fny][fnx] == '#'):
            break
        fx,fy = fnx,fny

    while(True):
        snx,sny = sx + dx[dir],sy + dy[dir]
        if(board[sny][snx] == 'O'):
            secondIn = True
            break
        #뒤에 온 거니까 앞에 있던 구슬과 같은 위치가 되면 break
        elif(board[sny][snx] == '#' or (sny == fy and snx == fx)):
            break
        sx,sy = snx,sny
    
    #움직인 좌표를 업데이트 해줌
    if(f == 0):
        redx,redy,bluex,bluey = fx,fy,sx,sy
    else:
        redx,redy,bluex,bluey = sx,sy,fx,fy


    #빨강은 들어가고 파랑은 안들어 갔을 때
    if((firstIn and f == 0 and not secondIn) or (secondIn and s == 0 and not firstIn)):
        return [1,redx,redy,bluex,bluey]
    #뭐라도 하나가 들어갔을 때(파랑이 들어갔거나 둘 다 들어갔거나)
    elif(firstIn or secondIn):
        return [-1,redx,redy,bluex,bluey]
    #아무것도 안들어갔으면 잘 옮겨진거임
    else:
        return [0,redx,redy,bluex,bluey]
    

def bfs(redx,redy,bluex,bluey):
    q = deque()
    q.append([redx,redy,bluex,bluey,0])
    while(q):
        now = q.popleft()
        [rx,ry,bx,by,val] = now
        if(val == 10):
            continue
        for i in range(4):
            [res,nrx,nry,nbx,nby] = moveMarble(rx,ry,bx,by,i)
            if(res == -1):
                continue
            if(res == 1):
                return val + 1
            q.append([nrx,nry,nbx,nby,val+1])
    return -1

n,m = map(int,sys.stdin.readline().split())

board = []
for i in range(n):
    board.append(list(sys.stdin.readline()))

for i in range(n):
    for j in range(m):
        if(board[i][j] == 'R'):
            redx,redy = j,i
        if(board[i][j] == 'B'):
            bluex,bluey = j,i

ans = bfs(redx,redy,bluex,bluey)
print(ans)
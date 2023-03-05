import sys
input = sys.stdin.readline


n,m,x,y,k = map(int,input().split())

board = []
for _ in range(n):
  board.append(list(map(int,input().split())))
  
movement = list(map(int,input().split()))


# 위,뒤,동,서,앞,밑
dice = [0,0,0,0,0,0,0]

#지도에서 움직이는 함수
def movedice(direction):
  dx = [0,0,0,-1,1]
  dy = [0,1,-1,0,0]
  global n,m,x,y
  #x가 세로,y가 가로
  ny = y + dy[direction]
  nx = x + dx[direction]
  #바깥으로 움직이려고 하면 무시한다
  if(ny < 0 or ny >= m or nx < 0 or nx >= n):
    return False
  #동쪽으로 움직인다.
  if(direction == 1):
    temp = dice[6]
    #밑 = 동
    dice[6] = dice[3]
    #동 = 위
    dice[3] = dice[1]
    #위 = 서
    dice[1] = dice[4]
    #서 = 밑
    dice[4] = temp
  #서쪽으로 움직인다.
  elif(direction == 2):
    temp = dice[6]
    #밑 = 서
    dice[6] = dice[4]
    #서 = 위
    dice[4] = dice[1]
    #위 = 동
    dice[1] = dice[3]
    #동 = 밑
    dice[3] = temp
  #북쪽으로 움직인다.
  elif(direction == 3):
    temp = dice[6]
    #밑 = 뒤
    dice[6] = dice[2]
    #뒤 = 위
    dice[2] = dice[1]
    #위 = 앞
    dice[1] = dice[5]
    #앞 = 밑
    dice[5] = temp
  #남쪽으로 움직인다.
  elif(direction == 4):
    temp = dice[6]
    #밑 = 앞
    dice[6] = dice[5]
    #앞 = 위
    dice[5] = dice[1]
    #위 = 뒤
    dice[1] = dice[2]
    #뒤 = 밑
    dice[2] = temp
  if(board[nx][ny] == 0):
    board[nx][ny] = dice[6]
  else:
    dice[6] = board[nx][ny]
    board[nx][ny] = 0
  x = nx
  y = ny
  return True

for direction in movement:
  if(movedice(direction)):
    print(dice[1])
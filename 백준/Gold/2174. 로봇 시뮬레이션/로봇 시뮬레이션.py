import sys
input = sys.stdin.readline

def main():
  dx = [0,1,0,-1]
  dy = [1,0,-1,0]
  a,b = map(int,input().split())
  n,m = map(int,input().split())
  board = [[0] * (a+1) for _ in range(b+1)] 
  robots = []
  for i in range(n):
    [x,y,d] = input().split()
    x,y = map(int,[x,y])
    board[y][x] = i+1
    if(d == 'N'):
      d = 0
    elif(d == 'E'):
      d = 1
    elif(d =='S'):
      d = 2
    else:
      d = 3
    robots.append([x,y,d])
    
  for i in range(m):
    [robotIdx, op, repeat] = input().split()
    robotIdx = int(robotIdx) - 1
    repeat = int(repeat)
    
    robot = robots[robotIdx]
    for j in range(repeat):
      if(op == 'F'):
        board[robot[1]][robot[0]] = 0
        robot[0] += dx[robot[2]]
        robot[1] += dy[robot[2]]
        if(outOfRange(robot[1], robot[0],a,b)):
          print("Robot {0} crashes into the wall".format(robotIdx+1))
          return
        elif(board[robot[1]][robot[0]] != 0):
          print("Robot {0} crashes into robot {1}".format(robotIdx+1, board[robot[1]][robot[0]]))
          return
        board[robot[1]][robot[0]] = robotIdx+1
      elif(op == 'R'):
        robot[2] = (robot[2] + 1)%4 
      else:
        robot[2] = (robot[2] + 3)%4
  print("OK")
def outOfRange(y,x,a,b):
  return y < 1 or y > b or x < 1 or x > a



if __name__ == '__main__':
  main()
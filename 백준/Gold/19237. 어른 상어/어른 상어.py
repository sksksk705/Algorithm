import sys
input = sys.stdin.readline

# NxN 에 M개의 칸에 상어
# 자신의 냄새를 뿌리고 이동하는데 인접한 곳에 냄새가 없는 칸으로 간다.
# 없다면 자신의 냄새가 있는 칸으로 방향을 잡는다 이떄 특정 우선순위를 따른다.
# 이동한 뒤에 한 칸에 여러마리의 상어가 있으면 가장 작은 번호를 가진 상어를 제외하고
# 모두 쫒겨난다.

#방향
# 1:위 2:아래 3:왼 4:오
class Shark:
  def __init__(self):
    self.isAlive = True
  
  def setId(self,id):
    self.id = id
    
  def setD(self,d):
    self.d = d
    
  def setPos(self,x,y):
    self.x = x
    self.y = y
    
  def setPreference(self,preference):
    self.preference = preference
  
  def remainSmell(self,smellBoard):
    if(not self.isAlive):
      return smellBoard
    smellBoard[self.y][self.x] = [self.id,k]
    return smellBoard
  
  def dead(self):
    self.isAlive = False
  
def getNextPosition(s:Shark, board, smellBoard):
  if(not s.isAlive):
    return
  #방향
# 1:위 2:아래 3:왼 4:오
  dx = [0,0,0,-1,1]
  dy = [0,-1,1,0,0]
  board[s.y][s.x] = 0
  nextx = -1
  nexty = -1
  nextd = -1
  for i in range(4):
    ny = s.y + dy[s.preference[s.d][i]]
    nx = s.x + dx[s.preference[s.d][i]]
    if(ny < 0 or ny >= n or nx < 0 or nx >= n):
      continue
    #해당 방향에 냄새없는 칸 있다면 이동한다
    if not smellBoard[ny][nx]:
      nextx = nx
      nexty = ny
      nextd = s.preference[s.d][i]
      break
    #자기 냄새라면 
    if smellBoard[ny][nx][0] == s.id:
      if nextx != -1:
        continue
      nextx = nx
      nexty = ny
      nextd = s.preference[s.d][i]
  s.setPos(nextx,nexty)
  s.setD(nextd)
  #만약 해당 좌표에 이미 상어가 있다면 내가 작으면 걔가 죽고 아니면 내가 죽는다.
  if(board[s.y][s.x] != 0 and board[s.y][s.x] < s.id):
    s.dead()
  else:
    sharkList[board[s.y][s.x]].dead()
    board[s.y][s.x] = s.id

  return board,smellBoard

def isFinished():
  for i in range(2,m+1):
    if sharkList[i].isAlive:
      return False
  return True

def clearBoard():
  board = [[0] * n for _ in range(n)]
  return board

def updateSmell():
  for i in range(n):
    for j in range(n):
      if(smellBoard[i][j]):
        smellBoard[i][j][1] -= 1
        if(smellBoard[i][j][1] == 0):
          smellBoard[i][j] = None
  return smellBoard


n,m,k = map(int,input().split())
board = []
sharkList = []
smellBoard = [[None] * n for _ in range(n)]

for i in range(n):
  board.append(list(map(int,input().split())))
  
for i in range(m+1):
  sharkList.append(Shark())
sharkList[0].dead()

for i in range(n):
  for j in range(n):
    if(board[i][j] != 0):
      sharkList[board[i][j]].setId(board[i][j])
      sharkList[board[i][j]].setPos(j,i)

sharkDir = list(map(int,input().split()))
for i in range(1,m+1):
  sharkList[i].setD(sharkDir[i-1])
  sharkList[i].setPreference([[]])
  for j in range(4):
    sharkList[i].preference.append(list(map(int,input().split())))

day = 0
while(not isFinished() and day <= 1000):
  day += 1
  board = clearBoard()
  smellBoard = updateSmell()
  for i in range(1,m+1):
    sharkList[i].remainSmell(smellBoard)
  for i in range(1,m+1):
    getNextPosition(sharkList[i],board,smellBoard)

if(day > 1000):
  print(-1)
else:
  print(day)
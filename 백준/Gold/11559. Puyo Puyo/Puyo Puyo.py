import sys
input = sys.stdin.readline


def main():
  board = []
  for _ in range(12):
    board.append(list(input()))
  ans = 0
  while(True):
    visited = [[False] * 6 for _ in range(12)]
    haveExplode = False
    for i in range(12):
      for j in range(6):
        if(board[i][j] =='.' or visited[i][j]):
          continue
        explode = []
        visited[i][j] = True
        cnt = dfs(j,i,board,visited,explode)
        if(cnt >= 4):
          explode.append((i,j))
          haveExplode = True
          for y,x in explode:
            board[y][x] = '.'
    if(not haveExplode):
      break
    ans += 1
    board = update_board(board)
  print(ans)
    
    
def dfs(x,y,board, visited,explode):
  dx = [0,0,-1,1]
  dy = [-1,1,0,0]
  ans = 1
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if(outOfRange(nx,ny) or visited[ny][nx] or board[ny][nx] != board[y][x]):
      continue
    visited[ny][nx] = True
    explode.append((ny,nx))
    ans += dfs(nx,ny,board,visited,explode)
  return ans

def update_board(board):
  for j in range(6):
    bottom = 11
    for i in range(11,-1,-1):
      if(board[i][j] != '.'):
        board[bottom][j] = board[i][j]
        bottom -= 1
    for i in range(bottom,-1,-1):
      board[i][j] = '.'
  return board
  
def outOfRange(x,y):
  return x < 0 or x >= 6 or y < 0 or y >= 12

if __name__ == '__main__':
  main()
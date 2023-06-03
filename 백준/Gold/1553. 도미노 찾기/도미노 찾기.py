import sys
input = sys.stdin.readline
ROW = 8
COL = 7
domino = []
for i in range(7):
    for j in range(i, 7):
        domino.append((i, j))

answer = []
for i in range(8):
    answer.append(list(map(int,list(input().strip()))))

res = 0
temp = [[-1]*COL for _ in range(ROW)]
def dfs(idx):
  global res
  if idx >= 28:
    res += 1
    return
  for i in range(ROW):
    for j in range(COL):
      #다른 도미노가 놓여져 있으면 패스
      if temp[i][j] != -1:
        continue
      
      if answer[i][j] == domino[idx][0]:
        # 0도
        if j + 1 < COL and answer[i][j+1] == domino[idx][1] and temp[i][j + 1 ] == -1:
          temp[i][j] = domino[idx][0] 
          temp[i][j+1] = domino[idx][1]
          dfs(idx+1)
          temp[i][j] = temp[i][j+1] = -1
        # 90도
        if i + 1 < ROW and answer[i+1][j] == domino[idx][1] and  temp[i+1][j] == -1:
          temp[i][j] = domino[idx][0] 
          temp[i+1][j] = domino[idx][1]
          dfs(idx+1)
          temp[i][j] = temp[i+1][j] = -1
          
      if(domino[idx][0] == domino[idx][1]):
        continue
      
      if answer[i][j] == domino[idx][1]:
        #180도
        if j + 1 < COL and answer[i][j+1] == domino[idx][0] and temp[i][j + 1] == -1:
          temp[i][j] = domino[idx][1] 
          temp[i][j+1] = domino[idx][0]
          dfs(idx+1)
          temp[i][j] = temp[i][j+1] = -1
        #270
        if i + 1 < ROW and answer[i+1][j] == domino[idx][0] and temp[i+1][j] == -1:
          temp[i][j] = domino[idx][1] 
          temp[i+1][j] = domino[idx][0]
          dfs(idx+1)
          temp[i][j] = temp[i+1][j] = -1

dfs(0)
print(res)
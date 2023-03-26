# 두명이 씨앗을 심었으니 다 덮어지는 경우의 수를 찾아내야함
# 왼쪽 위부터 시작해서 가로 가거나 오른쪽으로 가거나 해야함

import sys
input = sys.stdin.readline
n,m,k = map(int,input().split())

def isCovered():
  for i in range(n):
    for j in range(m):
      if farm[i][j] == 1:
        return False
  return True

def canSeed(y,x):
  horizon = True
  vertical = True
  for i in range(1,k):
    if x + i >= m or farm[y][x + i] == 0:
      horizon = False
      break
  for i in range(1,k):
    if y + i >= n or farm[y+i][x] == 0:
      vertical = False
      break
  return (horizon,vertical)
    
def dfs(depth):
  if(depth == 1):
    if isCovered():
      ans = []
      for i in range(n):
        for j in range(m):
          if farm[i][j] == 6:
            ans.append((i+1,j+1))
      print(len(ans))
      for pos in ans:
        print(pos[0],pos[1])
      exit()
    return
  for i in range(n):
    for j in range(m):
      if farm[i][j] != 0:
        horizon,vertical = canSeed(i,j)
        if(vertical):
          for l in range(i,i+k):
            if(farm[l][j] != 0):
              farm[l][j] += 3
          dfs(depth + 1)
          for l in range(i+k-1,i-1,-1):
            if(farm[l][j] != 0):
              farm[l][j] -= 3
              
        if(horizon):
          for l in range(j,j+k):
            if(farm[i][l] != 0):
              farm[i][l] += 3
          dfs(depth + 1)
          for l in range(j+k-1,j-1,-1):
            if(farm[i][l] != 0):
              farm[i][l] -= 3
        

farm = []
for i in range(n):
  farm.append(list(map(int,input().split())))

x = y = -1
horizon = vertical = False
for i in range(n):
  if x != -1: break
  for j in range(m):
    if(farm[i][j] != 0):
      horizon,vertical = canSeed(i,j)
      if horizon or vertical:
        y = i
        x = j
        break

if horizon:
  for l in range(x,x+k):
    if(farm[y][l] != 0):
      farm[y][l] += 2
  dfs(0)
if vertical:
  for l in range(y,y+k):
    if(farm[l][x] != 0):
      farm[l][x] += 2
  dfs(0)
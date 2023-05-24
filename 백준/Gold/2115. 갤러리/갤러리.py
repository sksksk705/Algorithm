# 2115 갤러리

# 행마다 가면서 블럭과 아래쪽 블럭이 색이 다르면 True
# 그전 행과 색이 같으면서 아래쪽 블럭과 색이 다르면 cnt += 1

# 열마다 가면서 블럭과 오른쪽 블럭의 색이 다르면 True
# 그전 열과 색이 같으면서 오른쪽 블럭과 색이 다르면 cnt += 1



m,n = map(int,input().split())

gallary = []
for i in range(m):
  gallary.append(list(input()))
  

cnt = 0
for i in range(m-1):
  diff = False
  for j in range(1,n):
    if gallary[i][j] != gallary[i+1][j]:
      if diff and gallary[i][j-1] == gallary[i][j]:
        cnt += 1
        diff = False
      else:
        diff= True
    else:
      diff = False
      

for i in range(n-1):
  diff = False
  for j in range(1,m):
    if gallary[j][i] != gallary[j][i+1]:
      if diff and gallary[j-1][i] == gallary[j][i]:
        cnt += 1
        diff = False
      else:
        diff= True
    else:
      diff = False
      
print(cnt)
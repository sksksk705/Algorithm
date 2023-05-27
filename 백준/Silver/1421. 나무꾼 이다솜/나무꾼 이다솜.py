n,c,w = map(int,input().split())

trees = []
for i in range(n):
  trees.append(int(input()))

height = [0] * 10001
for i in range(n):
  height[trees[i]] += 1
  

unit = max(trees)
res = 0
for i in range(1,unit+1):
  # i = 팔 나무의 단위 길이
  price = 0
  # j번째 나무를 i로 만들려면 몇번 잘라야하는지 몇개나 나오는지
  for j in range(n):
    if trees[j] < i:
      continue
    cnt = trees[j] // i
    cut = cnt
    if trees[j] % i == 0:
      cut -= 1
    profit = cnt * w * i - cut * c
    price += profit if profit > 0 else 0
  res = max(res,price)

print(res)
import sys
input = sys.stdin.readline


n = int(input())
while n != 0:
  dolls = []
  for i in range(n):
    dolls.append(int(input()))
    
  m = dict()
  res = 0
  for i in range(n):
    if m.get(dolls[i]):
      m[dolls[i]] += 1
    else:
      m[dolls[i]] = 1
    if m.get(dolls[i]) > res:
      res = m[dolls[i]]
  print(res)
  n = int(input())
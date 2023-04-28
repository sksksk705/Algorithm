import sys
input = sys.stdin.readline

n = int(input())
lst = list(map(int,input().split()))
listed = [False] * n
cnt = 0
while cnt < n:
  for i in range(n):
    if lst[i] == 0 and not listed[i]:
      listed[i] = True
      print(i+1,end=" ")
      cnt += 1
      for j in range(i):
        lst[j] -= 1
      break
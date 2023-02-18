import sys


dsum = [0]

n,m = map(int,sys.stdin.readline().split())

num_list = list(map(int,sys.stdin.readline().split()))

for i in num_list:
  dsum.append(dsum[-1] + i)

for i in range(m):
  fr, to = map(int,sys.stdin.readline().split())
  print(dsum[to] - dsum[fr-1])
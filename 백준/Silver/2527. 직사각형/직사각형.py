import sys
input = sys.stdin.readline

def solution(l,t,r,b,l2,t2,r2,b2):
  if(l > r2 or r < l2 or t > b2 or b < t2):
    return 'd'
  if((r ==l2 and b == t2) or (l == r2 and b == t2) or(r == l2 and t == b2) or (l == r2 and t == b2)):
    return 'c'
  if(r == l2 or b == t2 or l == r2 or t == b2):
    return 'b'
  else:
    return 'a'

  

for i in range(4):
  l,t,r,b,l2,t2,r2,b2 = map(int,input().split())
  res = solution(l,t,r,b,l2,t2,r2,b2)
  if(res == 'd'):
    res = solution(l2,t2,r2,b2,l,t,r,b)
  print(res)
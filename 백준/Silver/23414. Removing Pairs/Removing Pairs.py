#23414번 Removing Pairs
#완전탐색? index가 짝,홀,짝,홀이 되어야함.
#발견한 걸 기준으로 +1부터 2개씩 건너 뛰면서 만들어지면 YES 아니면 NO
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

s = input().strip()
t = input().strip()

def findLetter(findIdx, startIdx):
  if(findIdx == len(s)):
    return True
  for i in range(startIdx, len(t),2):
    if(t[i] == s[findIdx]):
      return findLetter(findIdx+1, i+1)
  return False

if((len(t)-len(s)) % 2 == 0 and findLetter(0,0)):
  print("YES")
else:
  print("NO")
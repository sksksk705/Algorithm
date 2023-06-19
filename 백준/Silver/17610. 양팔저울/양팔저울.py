import sys
input = sys.stdin.readline

k = int(input())
weights = list(map(int, input().split()))

s = sum(weights)

result = [1] * (s+1)
result[0] = 0
#가능한 경우의 수 
#왼쪽, 오른쪽, 안 놓기
def solution(idx, left, right):
  if idx == k:
    if left < right:
      result[right - left] = 0
    return
  solution(idx+1,left,right)
  solution(idx+1, left + weights[idx], right)
  solution(idx+1,left,right+weights[idx])
  
solution(0,0,0)  

print(sum(result))
# 이분탐색으로 가장 0과 차이가 작은 것을 찾아낸다.
# 찾은 수에서 자기 자신이면 하지 말고 왼쪽 mid 오른쪽 1개씩 3개 후보군

def binary_search(a):
  lo = 0
  hi = n-1
  while(lo <= hi):
    mid = int((lo + hi) /2)
    if(plask[mid] == a):
      return mid
    if(plask[mid] < a):
      lo = mid + 1
    else:
      hi = mid - 1
  return lo

n = int(input())
plask = sorted(list(map(int,input().split())))
best = 2**31-1
res = [-1,-1]
for i in range(n):
  target = 0 - plask[i]
  idx = binary_search(target)
  for j in range(idx-1 ,idx + 2):
    if(j < 0 or j == i or j >= n):
      continue
    if abs(0 - plask[i] - plask[j]) < best:
      best = abs(0 - plask[i] - plask[j])
      res[0] = min(plask[i],plask[j])
      res[1] = max(plask[i],plask[j])
print(*res)
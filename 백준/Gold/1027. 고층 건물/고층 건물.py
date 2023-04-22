import sys
input = sys.stdin.readline

#N = 50
n = int(input())
buildings = list(map(int,input().split()))

#기울기가 더 가파르면 볼 수 없다.
# idx = 현재 빌딩, delta = 방향, level = 기울기
def dfs(start, dist, delta, level):
  if start + dist*delta < 0 or start + dist*delta >= n:
    return 0
  nextHeight = buildings[start+dist*delta]
  nowLevel =  (nextHeight - buildings[start])/dist
  if nowLevel <= level:
    return dfs(start, dist+1, delta, level)
  return dfs(start, dist+1, delta, nowLevel) + 1
  
ans = 0
MIN_LEVEL = -100000000001
for i in range(n):
  ans = max(ans, dfs(i,1,-1,MIN_LEVEL)+dfs(i,1,1,MIN_LEVEL))
print(ans)
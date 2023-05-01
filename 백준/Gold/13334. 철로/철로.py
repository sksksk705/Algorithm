import heapq
import sys
from collections import deque

input = sys.stdin.readline
INF = 100000001
n = int(input())
lines = []
for i in range(n):
    h,o = map(int,input().split())
    lines.append((max(h,o),min(h,o)))
d = int(input())

# 끝이 작을 수록
# 앞이 클 수록
lines.sort()

start = -INF*2
end = -INF*2
contain = []
ans = 0
for i in range(n):
    ed = lines[i][0]
    st = lines[i][1]
    # 선분 끝을 지정해준다.
    end = ed
    # 시작점을 현재 포함하는 선분 구간에 넣어준다.
    heapq.heappush(contain,st)
    
    # 시작점부터 현재 현재 선분 끝까지 범위가 초과되면 뺀다.
    while contain:
        start = contain[0]
        if end - start > d:
          heapq.heappop(contain)
        else:
          break
          
    # 현재 끝에서 포함할 수 있는 선분들의 수를 저장한다.
    ans = max(ans,len(contain))

print(ans)
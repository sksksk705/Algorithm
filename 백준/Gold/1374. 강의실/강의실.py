import heapq
import sys
input = sys.stdin.readline

n = int(input())
lst = []
for i in range(n):
  idx,start,end = map(int,input().split())
  lst.append((start,end,idx))

startList = sorted(lst,key=lambda x : x[0])
endList = sorted(lst,key=lambda x : x[1])

started = [False] * (n+1)

ans = 0
sti = edi = 0
running = 0
while edi < n:
  #가장 빨리 끝나는 수업을 찾는다.
  if not started[endList[edi][2]]:
    #시작한 적이 없다면 진행중인 수업에 추가한다
    running += 1
    started[endList[edi][2]] = True
  endTime = endList[edi][1]
  # 해당 수업과 동시에 진행되는 모든 수업을 찾는다.
  while sti < n and startList[sti][0] < endTime:
    #만약 시작한 적이 없는 수업이라면 현재 진행 중인 수업에 추가한다.
    if not started[startList[sti][2]]:
      running += 1
      started[startList[sti][2]] = True
    sti += 1
  ans = max(ans,running)
  edi += 1
  running -= 1
print(ans)
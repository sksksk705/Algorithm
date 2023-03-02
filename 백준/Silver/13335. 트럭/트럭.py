from collections import deque
import sys
input = sys.stdin.readline

n,w,l = map(int,input().split())

trucks = list(map(int,input().split()))

queue = deque()
time = 0
weight = 0
while queue or trucks:
    time += 1
    if queue:
        insertTime = queue[0][0]
        if time - insertTime >= w:
            weight -= queue.popleft()[1]
    if trucks:
        if weight + trucks[0] <= l:
            weight += trucks[0]
            queue.append((time,trucks[0]))
            trucks.pop(0)

print(time)
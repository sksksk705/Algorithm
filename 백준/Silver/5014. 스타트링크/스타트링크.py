import sys
input = sys.stdin.readline

f,s,g,u,d = map(int,input().split())

stairs = [-1]*(f+1)
q = [s]
stairs[s] = 0

while q:
    floor = q.pop(0)
    if floor + u <= f and stairs[floor + u] == -1:
        stairs[floor + u] = stairs[floor] + 1
        q.append(floor+u)
    if floor - d > 0 and stairs[floor - d] == -1:
        stairs[floor - d] = stairs[floor] + 1
        q.append(floor-d)

if stairs[g] != -1:
    print(stairs[g])
else:
    print("use the stairs")
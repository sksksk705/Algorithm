import sys
input = sys.stdin.readline

a,d,k = map(int,input().split())

winning = d
time = a
cnt = 0
possible = 0
prev = 0
while True:
    possible += (1-prev) * winning/100 * time
    if winning >= 100:
        break
    prev = prev + (1-prev) * winning/100
    winning = min(100, winning + winning * k/100)
    time += a

print(format(possible,'.7f'))
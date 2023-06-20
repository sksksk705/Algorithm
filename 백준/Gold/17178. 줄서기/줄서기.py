import sys
input = sys.stdin.readline

# 모든 사람을 정렬해놓는다.
# 맨 앞에 있는 사람이나 대기중인 사람의 맨 뒤 사람이 정렬 순서랑 맞으면 pop
# 다 안 빠지면 BAD

n = int(input())
queue = []
for i in range(n):
    q = list(input().strip().split(' '))
    for i in range(5):
        queue.append(list(q[i].split('-')))
        
sorted_queue = sorted(queue,key=lambda x : (x[0],int(x[1])))

ready = []
for i in range(n*5):
    while ready and ready[len(ready)-1] == sorted_queue[0]:
        ready.pop()
        sorted_queue.pop(0)
    if queue[0] == sorted_queue[0]:
        queue.pop(0)
        sorted_queue.pop(0)
    else:
        ready.append(queue.pop(0))

if list(reversed(ready)) == sorted_queue:
    print("GOOD")
else:
    print("BAD")
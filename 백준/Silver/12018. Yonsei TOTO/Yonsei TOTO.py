import sys
input = sys.stdin.readline

n,m = map(int,input().split())

lectures = [0] * n
for i in range(n):
    p,l = map(int,input().split())
    students = sorted(list(map(int,input().split())))
    if(p < l):
        lectures[i] = 1
    else:
        lectures[i] = students[p-l]
    
lectures.sort()
listen = 0
index = 0
while(index < n):
    m -= lectures[index]
    index += 1
    if(m >= 0):
        listen += 1
    else:
        break
print(listen)
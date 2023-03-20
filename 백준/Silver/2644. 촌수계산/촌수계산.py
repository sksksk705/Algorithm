import sys
input = sys.stdin.readline

n = int(input())
a,b = map(int,input().split())
m = int(input())

parent = [i for i in range(n+1)] 

for i in range(m):
    p,c = map(int,input().split())
    parent[c] = p

ap = [a]
bp = [b]
while(parent[a] != a):
    ap.append(parent[a])
    a = parent[a]

while(parent[b] != b):
    bp.append(parent[b])
    b = parent[b]
    
for p in ap:
    if p in bp:
        print(ap.index(p) + bp.index(p))
        exit()
print(-1)
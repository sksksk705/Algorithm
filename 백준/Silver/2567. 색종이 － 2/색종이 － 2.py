import sys
input = sys.stdin.readline


n  = int(input())

paper = [[0 for _ in range(102)] for _ in range(102)]

for t in range(n):
    l, b = map(int, input().split())
    for i in range(10):
        for j in range(10):
            paper[b+i][l+j] = 1

res = 0
for i in range(1, 100):
    for j in range(1,100):
        if(paper[i][j] == 1):
            res += 1 - paper[i-1][j]
            res += 1 - paper[i][j-1]
            res += 1 - paper[i+1][j]
            res += 1 - paper[i][j+1]
print(res)
import sys
input = sys.stdin.readline

n = int(input())
words = []
for i in range(n):
    words.append(input().rstrip())

words.sort(key=lambda x:len(x))

res = 0
for i in range(n-1):
    isPrefix = False
    for j in range(i+1,n):
        size = len(words[i])
        for k in range(size+1):
            if k == size:
                isPrefix = True
                break
            if words[i][k] != words[j][k]:
                break
        if isPrefix:
            break
    if not isPrefix:
        res += 1

print(res+1)
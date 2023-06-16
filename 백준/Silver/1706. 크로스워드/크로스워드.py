import sys
import heapq
input = sys.stdin.readline

pq = []

n, m = map(int, input().split())
words = []
for i in range(n):
    words.append(list(input()))


for i in range(n):
    word = []
    for j in range(m):
        if words[i][j] == '#':
            if len(word) > 1:
                heapq.heappush(pq, ''.join(word))
            word = []
        else:
            word.append(words[i][j])
    if len(word) > 1:
        heapq.heappush(pq, ''.join(word))

for i in range(m):
    word = []
    for j in range(n):
        if words[j][i] == '#':
            if len(word) > 1:
                heapq.heappush(pq, ''.join(word))
            word = []
        else:
            word.append(words[j][i])
    if len(word) > 1:
        heapq.heappush(pq, ''.join(word))

print(pq[0])
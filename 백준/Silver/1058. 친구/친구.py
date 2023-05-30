import sys
input = sys.stdin.readline

n = int(input())

graph = []

for i in range(n):
    graph.append(list(input()))

friend = [0] * n
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        isFriend = False
        for k in range(n):
            if graph[i][j]=='Y' or (graph[i][k] == 'Y' and graph[k][j] == 'Y'):
                isFriend = True
                break
        if isFriend:
            friend[i] += 1
print(max(friend))
#2098 외판원의 순회
#visited배열을 2진수로 바꿔서 dp로 사용하는 문제?

# 추가: visited |= (1<<i);
# 확인: visited & (1<<i):
# 제거: visited &= (not(1<<i)):
import sys

def tsp(now, visited):
    global n
    ret = dp[now][visited]
    if(ret != -1):
        return ret
    ret = 1234567899999
    if(visited == 2**n-1):
        if(graph[now][0] != 0):
            return graph[now][0]
        else:
            return ret
    for i in range(n):
        if(visited & (1<<i) or graph[now][i] == 0):
            continue
        visited |= (1<<i)
        ret = min(ret,tsp(i,visited)+graph[now][i])
        visited &= (~(1<<i))
    dp[now][visited] = ret
    return dp[now][visited]

n = int(sys.stdin.readline())
dp = [[-1 for _ in range(2**n)]for _ in range(n+1)]
graph = []

for i in range(n):
    graph.append(list(map(int,sys.stdin.readline().split())))

res = tsp(0,1)
print(res)
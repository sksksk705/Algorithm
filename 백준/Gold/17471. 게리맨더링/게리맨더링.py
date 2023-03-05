from collections import deque
import sys
input = sys.stdin.readline

# n = 10으로 굉장히 작다
# 모든 조합을 다 체크한다?


n = int(input())
population = list(map(int,input().split()))
population.insert(0,0)

graph = [[0] * (n+1) for _ in range(n+1)]
comb = []
for i in range(1,n+1):
    location = list(map(int,input().split()))
    for j in range(1, len(location)):
        graph[i][location[j]] = 1

# 어떤 숫자 조합에 따라 선거구를 만들 수 있는지 계산
def bfs(area):
    i = 0
    # 만들고자 하는 선거구에 포함되는 하나의 지역을 선택한다.
    while(not (1 << i)&area):
      i += 1
    # 해당 선거구를 포함시킨 뒤 만약 만들 선거구와 같다면 만들 수 있다고 한다.
    visited = 1 << i
    if(visited == area):
        return True
    
    # 해당 지역부터 탐색시작
    queue = deque()
    queue.append(i)
    while queue:
        start = queue.popleft()
        for i in range(1,n+1):
          # 해당 지역과 연결된 지역이 만들고자하는 선거구에 포함되며 방문한 적이 없다면 추가
          if graph[start][i] and (area & (1<<i)) and (not visited & (1 << i)):
            # 만들고 있는 선거구에 추가
            visited |= (1<<i)
            # 만들 선거구와 같다면 만들 수 있다.
            if(visited == area):
              return True
            queue.append(i)
    return False

def calcPopulation(area):
  res = 0
  for i in range(1,n+1):
    if area & (1 << i):
      res += population[i]
  return res

ans = 987654321
for i in range(2,2**(n+1)//2, 2):
  if(bfs(i) and bfs(2**(n+1)-i-2)):
    ans = min(ans,abs(calcPopulation(i)-calcPopulation(2**(n+1)-i-2)))

if(ans == 987654321):
  print(-1)
else:
  print(ans)
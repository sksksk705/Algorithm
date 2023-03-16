#99이하 4장 선택 가능
#최대로 만들 수 있는 수의 크기는 99999999


s = set()
n = int(input())
k = int(input())
visited = [False] * n

card = []
for i in range(n):
  card.append(input())

def bruteForce(level, res):
  if(level == k):
    s.add(res)
  for i in range(n):
    if not visited[i]:
      visited[i] = True
      bruteForce(level + 1, res + card[i])
      visited[i] = False

bruteForce(0,"")

print(len(s))
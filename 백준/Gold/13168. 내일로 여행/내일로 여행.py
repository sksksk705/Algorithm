# 딕셔너리에 저장하고 NxN배열 2개 써서 프림으로 다 만들어놓고 값 비교하기

def getInput():
  n,r = map(int,input().split())
  cities = list(input().strip().split())
  m = int(input())
  route = list(input().strip().split())
  k = int(input())
  
  trans = {"Subway":0,"Bus":1,"Taxi":2,"Airplane":3,
          "KTX":4,"S-Train":5,"V-Train":6,
          "ITX-Saemaeul":7,"ITX-Cheongchun":8,"Mugunghwa":9}
  normal = [[987654321] * n for _ in range(n)]
  tomorrow = [[987654321] * n for _ in range(n)]
  transTomorrow = [1,1,1,1,1,0.5,0.5,0,0,0]
  
  cityDict = {}

  idx = 0
  for i in range(n):
    if(cities[i] not in cityDict):
      cityDict[cities[i]] = idx
      idx += 1
    
  for i in range(m):
      route[i] = cityDict[route[i]]
    
  for i in range(k):
    transType, start,end,price = input().strip().split()
    normal[cityDict[start]][cityDict[end]] = min(int(price),normal[cityDict[start]][cityDict[end]])
    normal[cityDict[end]][cityDict[start]] = normal[cityDict[start]][cityDict[end]]
    
    tomorrow[cityDict[start]][cityDict[end]] = min(int(price) * transTomorrow[trans[transType]],tomorrow[cityDict[start]][cityDict[end]])
    tomorrow[cityDict[end]][cityDict[start]] = tomorrow[cityDict[start]][cityDict[end]]
    
  return [normal,tomorrow,route,r]
    

def prim(graph):
  n = len(graph)
  for k in range(n):
    for i in range(n):
      for j in range(n):
        if(i == j):
          graph[i][j] = 0
        else:
          graph[i][j] = min(graph[i][k] + graph[k][j],graph[i][j])
  return graph

def main():
  normal,tomorrow,route,r = getInput()
  normal = prim(normal)
  tomorrow = prim(tomorrow)
  
  start = route[0]
  normalPrice = 0
  tomorrowPrice = r
  for i in range(1,len(route)):
    normalPrice += normal[start][route[i]]
    tomorrowPrice += tomorrow[start][route[i]]
    start = route[i]
  if(tomorrowPrice < normalPrice):
    print("Yes")
  else:
    print("No")
  
if __name__ == "__main__":
  main()
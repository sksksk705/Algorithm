import sys
input = sys.stdin.readline
MAXI = 1100
MAXV = 987654321
c,n = map(int,input().split())


city = []
for i in range(n):
  a,b = map(int,input().split())
  city.append((a,b))

cache = [MAXV] * MAXI
cache[0] = 0
for i in range(n):
  for j in range(city[i][1], MAXI):
    if j - city[i][1] != MAXV:
      cache[j] = min(cache[j],cache[j-city[i][1]]+city[i][0])

print(min(cache[c:]))
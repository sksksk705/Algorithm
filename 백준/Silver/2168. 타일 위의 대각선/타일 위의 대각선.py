x,y = map(int,input().split())

def gcd(a,b):
  if a % b == 0:
    return b
  return gcd(b,a%b)

print(x+y - gcd(x,y))
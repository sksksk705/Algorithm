def gcd(a,b):
    if a % b == 0:
        return b
    return gcd(b,a%b)

a,b = map(int,input().split())

for i in range(gcd(a,b)):
    print(1,end="")
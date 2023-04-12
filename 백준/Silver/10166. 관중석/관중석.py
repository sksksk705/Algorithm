def GCD(a,b):
    if(a%b) == 0:
        return b
    else:
        return GCD(b,a%b)

d1,d2 = map(int,input().split())

d= dict()
for i in range(d1,d2+1):
    for j in range(1,i+1):
        gcd = GCD(j,i)
        x = j//gcd
        y = i//gcd
        if (x,y) not in d:
            d[(x,y)] = 1
print(len(d))
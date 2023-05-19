c,p = map(int,input().split())
block = list(map(int,input().split()))

# 1번: 2가지    1:0 2:0000
def check1(x):
    if x+3 >= c:
        return 1
    for i in range(4):
        if block[x+i] != block[x]:
            return 1
    return 2

# 2번: 1가지    1:00
def check2(x):
    if x+1 >= c:
        return 0
    if block[x+1] == block[x]:
        return 1
    return 0
# 3번: 2가지    1:001 2:0-1
def check3(x):
    can1 = 1 if x+2 < c and block[x] == block[x+1] == block[x+2]-1 else 0
    can2 = 1 if x+1 < c and block[x] == block[x+1]+1 else 0
    return can1+can2

# 4번: 2가지    1:0-1-1 2:01
def check4(x):
    can1 = 1 if x+2 < c and block[x] == block[x+1]+1 == block[x+2]+1 else 0
    can2 = 1 if x+1 < c and block[x] == block[x+1]-1 else 0
    return can1+can2

# 5번: 4가지    1:000 2:01 3:0-10 4:0-1
def check5(x):
    can1 = 1 if x+2 < c and block[x] == block[x+1] == block[x+2] else 0
    can2 = 1 if x+1 < c and block[x] == block[x+1]-1 else 0
    can3 = 1 if x+2 < c and block[x] == block[x+1]+1 == block[x+2] else 0
    can4 = 1 if x+1 < c and block[x] == block[x+1]+1 else 0
    return can1+can2+can3+can4

# 6번: 4가지    1:000 2:00 3:011 4:0-2
def check6(x):
    can1 = 1 if x+2 < c and block[x] == block[x+1] == block[x+2] else 0
    can2 = 1 if x+1 < c and block[x] == block[x+1] else 0
    can3 = 1 if x+2 < c and block[x] == block[x+1]-1 == block[x+2]-1 else 0
    can4 = 1 if x+1 < c and block[x] == block[x+1]+2 else 0
    return can1+can2+can3+can4

# 7번: 4가지    1:000 2:02 3:00-1 4:00
def check7(x):
    can1 = 1 if x+2 < c and block[x] == block[x+1] == block[x+2] else 0
    can2 = 1 if x+1 < c and block[x] == block[x+1]-2 else 0
    can3 = 1 if x+2 < c and block[x] == block[x+1] == block[x+2]+1 else 0
    can4 = 1 if x+1 < c and block[x] == block[x+1] else 0
    return can1+can2+can3+can4

def checkBlocks(p):
    ans = 0
    for i in range(c):
        match(p):
            case 1: ans += check1(i)
            case 2: ans += check2(i)
            case 3: ans += check3(i)
            case 4: ans += check4(i)
            case 5: ans += check5(i)
            case 6: ans += check6(i)
            case 7: ans += check7(i)
    return ans

print(checkBlocks(p))
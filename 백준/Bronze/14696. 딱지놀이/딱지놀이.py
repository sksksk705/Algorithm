import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a = list(map(int,input().split()))[1:]
    b = list(map(int,input().split()))[1:]

    if(sorted(a) == sorted(b)):
        print("D")
        continue

    aPic = [0 for i in range(5)]
    bPic = [0 for i in range(5)]
    for pic in a:
        aPic[pic] +=1
    for pic in b:
        bPic[pic] +=1

    for i in range(4,-1,-1):
        if(aPic[i] == bPic[i]):
            continue
        elif(aPic[i] > bPic[i]):
            print("A")
            break
        else:
            print("B")
            break
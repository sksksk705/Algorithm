import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    num = [i for i in range(1,n+1)]
    stack = list(map(int,input().split()))

    possible = True;
    for i in range(n):
        if(stack[i] > i):
            possible = False;
            break
    
    if(possible):
        res = []
        while(len(stack) > 0):
            res.insert(0,num.pop(stack.pop()))
        print(*res)
    else:
        print("IMPOSSIBLE")
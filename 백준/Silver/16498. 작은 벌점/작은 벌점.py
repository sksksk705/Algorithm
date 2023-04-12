import sys
input = sys.stdin.readline

def binary_search(target, data):
    data.sort()
    start = 0
    end = len(data) - 1

    while start <= end:
        mid = (start + end) // 2

        if data[mid] == target:
            return mid # 함수를 끝내버린다.
        elif data[mid] < target:
            start = mid + 1
        else:
            end = mid -1
    return start
a,b,c = map(int,input().split())
al = sorted(list(map(int,input().split())))
bl = sorted(list(map(int,input().split())))
cl = sorted(list(map(int,input().split())))

panalty = 2**64-1
for i in range(a):
    fa = binary_search(al[i],bl)
    for j in range(max(0,fa-1),min(b,fa+1)):
        fb = binary_search(bl[j],cl)
        for k in range(max(0,fb-1),min(c,fb+1)):
            panalty = min(panalty,abs(max(al[i],bl[j],cl[k]) - min(al[i],bl[j],cl[k])))

print(panalty)
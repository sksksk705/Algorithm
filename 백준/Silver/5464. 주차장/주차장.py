import sys
input = sys.stdin.readline

n,m = map(int,input().split())

pay = []
for i in range(n):
    pay.append(int(input()))

weight = []
for i in range(m):
    weight.append(int(input()))

s = set()
parking = [-1] *(m+1)
q = []
ans = 0
for i in range(2*m):
    car = int(input())
    if car > 0:
        #들어가는 차량인데 만약 모든 주차장이 꽉 찾으면 대기
        if len(s) >= n:
            q.append(car)
            continue
        for i in range(n):
            if i not in s:
                parking[car] = i
                s.add(i)
                break
    else:
        ans += pay[parking[-car]] * weight[-car-1]
        s.remove(parking[-car])
        parking[-car] = -1
        if q:
            car = q.pop(0)
            for i in range(n):
                if i not in s:
                    parking[car] = i
                    s.add(i)
            

print(ans)
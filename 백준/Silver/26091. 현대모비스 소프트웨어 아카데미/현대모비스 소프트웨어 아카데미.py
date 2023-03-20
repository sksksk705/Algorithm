# 두명씩 짝지을 때 m이상을 가장 많이 만들 수 있는 방법
# 그리디: 가장 큰 값에서 m 이상이 될 수 있는 가장 작은 수를 팀으로 한다.

import sys
input = sys.stdin.readline

n,m = map(int,input().split())
students = sorted(list(map(int,input().split())))

start = 0
end = n-1

ans = 0
while(start < end):
    if(students[start] + students[end] >= m):
        ans += 1
        end -= 1
    start += 1
print(ans)
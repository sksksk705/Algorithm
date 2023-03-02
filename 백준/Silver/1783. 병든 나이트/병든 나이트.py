# 병든 나이트
# 나이트는 오른쪽으로 밖에 움직이지 않는다.
# 따라서 오른쪽을 최소한으로 사용하는 방향으로 사용해야 한다.
# 세로 3이상 가로 6 이상이어야 4가지 방법을 다 사용할 수 있다.
import sys
input = sys.stdin.readline

n,m = map(int,input().split())

if(n >= 3 and m >= 6):
    print(m - 2)
elif(n >= 3):
    print(min(4,m))
elif(n >= 2):
    print(min(4,(m-1)//2 + 1))
else:
    print(1)
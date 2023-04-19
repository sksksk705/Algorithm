import heapq
import sys
input = sys.stdin.readline

# 0번부터
# 짝 수명 남았으면 밤 죽일 사람 고름
# 홀수면 낮, 죄 한명 
# 지금 나 혼자.
# 유죄지수 낮에 시민들이 어떤 참가자를 고를지 쓰임
# i를 죽이면 j는 R[i][j]만큼 변함
# 낮에는 유죄지수 가장 높은 사람 죽음(여러명이면 그 중 번호가 가장 작은 사람 죽음)
# 가장 게임을 오래 지속하는 방법



#N = 16
n = int(input())

guilty = list(map(int,input().split()))
guiltMap = []
for i in range(n):
    guiltMap.append(list(map(int,input().split())))

eunji = int(input())
# 유죄지수가 높은 사람 죽임
# 남은 사람 중에서 아무나 죽임
ans = 0

def deadUpdate(idx,delta):
    global guilty
    for i in range(n):
        guilty[i] += guiltMap[idx][i] * delta

def simulation(day,alive,alivecnt):
    global ans
    if(alivecnt % 2 == 1):
        personToDead = morning(alive)
        if personToDead == eunji:
            ans = max(ans,day);
            return
        alive[personToDead] = False
        alivecnt -= 1
    if(alivecnt % 2 == 0):
        for i in range(n):
            if alive[i] and i != eunji:
                alive[i] = False
                deadUpdate(i,1)
                simulation(day+1,alive[:],alivecnt - 1)
                deadUpdate(i,-1)
                alive[i] = True

def morning(alive):
    pq = []
    for i in range(n):
        if(alive[i]):
            heapq.heappush(pq,(-guilty[i],i))
    dead = heapq.heappop(pq)
    return dead[1]

simulation(0,[True] * n,n)
print(ans)
# n = 1,000,000
# 우선순위 큐에 넣고 가장 낮은 게 K 이상일 때까지 두개 뽑아서 계산하고 넣기
import heapq
def solution(scoville, K):
    pq = []
    for spicy in scoville:
        heapq.heappush(pq, spicy)
    answer = 0
    while len(pq) > 1 and pq[0] < K:
        l_spi = heapq.heappop(pq)
        l2_spi = heapq.heappop(pq)
        heapq.heappush(pq,l_spi + l2_spi * 2)
        answer += 1
    
    if pq[0] < K:
        answer = -1
    return answer

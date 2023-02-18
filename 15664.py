import sys
def solve(num_list, m, depth,seq,prev):
    # 기저사례: 배열의 길이가 m과 같다면 출력하고 반환
    if(depth == m):
        print(*seq)
        return
    #현재 INDEX에서 이 숫자를 쓴 적이 있니?
    used = [0 for _ in range(10001)]
  
    # 정렬이 되어있기 때문에 이전 것보다 뒤 인덱스부터 시작
    for i in range(prev+1,len(num_list)):
        # 만약 현 뎁스에서 이미 사용한 숫자라면 건너뛴다.
        if(used[num_list[i]]):
            continue
        # 사용했다 체크해주고 수열에 더한 다음 다시 재귀로 진입
        used[num_list[i]] = 1
        seq.append(num_list[i])
        solve(num_list,m,depth+1,seq,i)
        seq.pop()
        
n,m = map(int,sys.stdin.readline().split())

num_list = list(map(int,sys.stdin.readline().split()))

num_list.sort()
solve(num_list,m,0,[],-1)

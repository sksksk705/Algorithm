import sys
input = sys.stdin.readline

MAXSIZE = 1000001
#대충 * 4로 트리크기 퉁치기
arr = [0]*MAXSIZE; segtree = [0] * MAXSIZE * 4;lazy = [0]  * MAXSIZE*4

#루트노드부터 시작
def create_segtree(node, start,end):
  #만약 리프노드라면 
  if start == end:
    #리프노드를 채워준다.
    segtree[node] = arr[start]
    return
  
  #리프노드가 아니라면
  mid = int((start+end)/2)
  #왼쪽 오른쪽 서브트리를 만들어준다
  create_segtree(node*2,start,mid)
  create_segtree(node*2+1,mid+1,end)
  #양쪽 서브트리의 합을 해당 노드에 저장
  segtree[node] = segtree[node*2] + segtree[node*2+1]
  
#start부터 end까지에 lazy값 반영하기
def update_lazy(node, start,end):
  #만약 lazy값이 존재하면 
  if lazy[node] != 0:
    # 현재 노드에 반영해줌.
    segtree[node] += (end-start+1)*lazy[node]
    #구간 노드라면 양쪽 서브트리에 lazy값을 물려준다.
    if start != end:
      lazy[node*2] += lazy[node]
      lazy[node*2+1] += lazy[node]
    #현재 노드 lazy반영 끝
    lazy[node] = 0

#구간 갱신 함수
def update_range(node,start,end,l,r,val):
  #방문하는 구간노드에 대해 lazy값 반영해주기.
  update_lazy(node,start,end)
  
  #갱신 구간에 포함되지 않는 노드 
  if(l > end or r < start): return
  
  #갱신 구간에 완전히 포함되는 노드
  if(l <= start and end <= r):
    # 구간의 크기 만큼 현재값을 곱해서 더해줌
    segtree[node] += (end - start + 1) * val
    #구간 노드라면 양쪽 자식에 lazy 추가
    if start != end:
      lazy[node*2] += val
      lazy[node*2+1] += val
    return
  
  # 걸치는 범위라면
  # 양쪽 서브트리에 대해 찾아가서 결과값을 현재 노드에 저장한다.
  mid = int((start + end)/2)    
  update_range(node*2,start,mid,l,r,val)
  update_range(node*2+1,mid+1,end,l,r,val)
  segtree[node] = segtree[node*2] + segtree[node*2+1];
  
def query(node,start,end,l,r):
  #해당 구간 노드에 대해 lazy값 갱신
  update_lazy(node,start,end)
  
  #포함되지 않는 범위라면 0 반환
  if(l > end or r < start): return 0
  
  #완전히 포함되는 범위라면 해당 구간합 반환
  if(l <= start and end <= r):return segtree[node]
  
  #걸치는 범위라면 양쪽 서브트리에 대해 쿼리 진행
  mid = int((start+end)/2)
  return query(node*2,start,mid,l,r) + query(node*2+1,mid+1,end,l,r)

def init():
  global n,m,k
  n,m,k = map(int,input().split())
  for i in range(1,n+1):
    arr[i] = int(input())
    
def main():
  init()
  create_segtree(1,1,n)
  
  for i in range(m+k):
    op = list(map(int,input().split()))
    # 갱신 연산
    if op[0] == 1:
      update_range(1,1,n,op[1],op[2],op[3])
    # 질의 연산
    else:
      print(query(1,1,n,op[1],op[2]))
      
if __name__ == "__main__":
  main()
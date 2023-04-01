import sys

  
def main():
  n,k = map(int,sys.stdin.readline().split())

  #물병 개수를 줄여야되는 경우
  #지금 걸 최대한 줄여봐도 안 되면 사야 됨
  bottles = []
  for _ in range(k-1):
    for i in range(25,-1,-1):
      bottle = pow(2,i)
      if(bottle <= n):
        n -= bottle
        if(n == 0):
          print(0)
          return
        break

  for i in range(26):
    bottle = pow(2,i)
    if(bottle >= n):
      print(bottle - n)
      return
  
  
if __name__ == "__main__":
  main()
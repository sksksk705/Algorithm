# 추는 1000개
# 최소무게 이하는 무조건 못 만드니까 최소무게가 2 이상이면 1
# 그 외에는 최대 무게 이하까지 최대 무게는 100만
# 최소값부터 만들다가 안 만들어지면 끝

n = int(input())
num_list = sorted(list(map(int,input().split())))

if(num_list[0] > 1):
  print(1)
  exit()
  
prefix = num_list[0]
for i in range(1,n):
  # 만들어진 적이 없는 숫자가 있다면 그 숫자는 못 만든다.
  if(num_list[i] > prefix+1):
    break
  prefix += num_list[i]
print(prefix + 1)
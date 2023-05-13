nums = list(map(int,input().split()))

nums.sort()

max_num = nums[-1] * nums[-2] * nums[-3]

for i in range(1,max_num):
  cnt = 0
  for j in range(5):
    if i % nums[j] == 0:
      cnt += 1
  if cnt >= 3:
    print(i)
    exit()
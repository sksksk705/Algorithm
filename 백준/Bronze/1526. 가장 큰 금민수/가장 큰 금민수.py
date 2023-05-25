n = int(input())


for i in range(n,3,-1):
  num = i
  isTrue = True
  while num > 0 and isTrue:
    if num % 10 == 4 or num % 10 == 7:
      num //= 10
      continue
    isTrue = False
  if isTrue:
    print(i)
    exit()
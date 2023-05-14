import math
l,r = map(int,input().split())

level = int(math.log10(l))

i = level
cnt = 0
while i > -1:
  if l // pow(10,i) == r // pow(10,i):
    if l // pow(10,i) == 8:
      cnt += 1
    l %= pow(10,i)
    r %= pow(10,i)
    i -= 1
  else:
    break

print(cnt)
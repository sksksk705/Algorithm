import sys
k = int(input())
n = 1
num = 0
while(k > num + 2**n):
	num += 2**n
	n+=1


k -= num+1

str = ""
for i in range(n-1,-1,-1):
	res = k//(2**i)
	if res == 1:
		str += '7'
	else:
		str +='4'
	k %= 2**i
print(str)
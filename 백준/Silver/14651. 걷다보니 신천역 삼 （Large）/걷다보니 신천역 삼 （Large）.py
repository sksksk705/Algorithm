import sys
input = sys.stdin.readline
MOD = 1000000009

n = int(input())
ans = 0

if n < 2:
    ans = 0
else:
    ans = 2

for i in range(n,2,-1):
    ans = ans * 3 % MOD

print(ans)
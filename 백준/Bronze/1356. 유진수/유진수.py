import math


n = input()


def get_mul(i):
    mul = 1
    for num in i:
        mul *= int(num)
    return mul


for i in range(1, len(n)):
    if (get_mul(n[:i]) == get_mul(n[i:])):
        print("YES")
        exit()
print("NO")
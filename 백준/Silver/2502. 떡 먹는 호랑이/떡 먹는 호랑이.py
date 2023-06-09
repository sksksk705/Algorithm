import sys
input = sys.stdin.readline

d, k = map(int, input().split())


def fibonacci(x):
    if x == 1:
        return 1
    if x == 2:
        return 1
    if x == 3:
        return 2
    return fibonacci(x-1) + fibonacci(x-2)


a = fibonacci(d-2)
b = fibonacci(d-1)

for i in range(1, k//a):
    if (k - i*a) % b == 0:
        print(i)
        print((k - i*a) // b)
        exit()
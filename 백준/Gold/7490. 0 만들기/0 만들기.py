tc = int(input())
op = [' ', '+', '-']


ps = []


def powerSet(idx, n, res):
    if idx == n-1:
        ps.append(res[:])
        return
    for i in range(3):
        res.append(i)
        powerSet(idx+1, n, res)
        res.pop()


for i in range(tc):
    n = int(input())
    ps = []
    powerSet(0, n, [])
    for path in ps:
        vq = [1]
        opq = []
        for j in range(len(path)):
            if path[j] == 0:
                val = vq.pop()
                vq.append(val * 10 + j + 2)
            else:
                vq.append(j+2)
                opq.append(path[j])
        res = vq.pop(0)
        while vq:
            if opq.pop(0) == 1:
                res = res + vq.pop(0)
            else:
                res = res - vq.pop(0)
        if res == 0:
            print(1, end="")
            for i in range(2, n+1):
                print(op[path[i-2]], end="")
                print(i, end="")
            print()
    print()
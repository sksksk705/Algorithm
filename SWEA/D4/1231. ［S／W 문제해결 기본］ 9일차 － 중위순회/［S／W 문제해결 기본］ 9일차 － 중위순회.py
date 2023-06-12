t = 10

def travel(tree, idx):
    if len(tree[idx]) > 1:
        travel(tree,int(tree[idx][1]))
    print(tree[idx][0],end="")
    if len(tree[idx]) > 2:
        travel(tree, int(tree[idx][2]))

for tc in range(t):
    n = int(input())
    tree = [[]for _ in range(n+1)]
    for i in range(n):
        vertex = list(input().split())
        tree[int(vertex[0])] = vertex[1:]
    print("#{0} ".format(tc+1),end="")
    travel(tree,1)
    print()

    
    
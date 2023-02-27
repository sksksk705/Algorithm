import sys
input = sys.stdin.readline

n,k = map(int,input().split())

student = [[0 for i in range(2)] for i in range(7)]

for i in range(n):
    gender, grade = map(int,input().split())
    student[grade][gender] += 1


res = 0
for i in range(2):
    for j in range(1, 7):
        if(student[j][i] == 0):
            continue
        res += student[j][i] // k
        if(student[j][i] % k != 0):
            res += 1;

print(res)
import sys
input = sys.stdin.readline

ip = list(input().strip().split(':'))

s = ""
if(ip.count("") > 1):
    ip.remove("")
for i in range(len(ip)):
    if(ip[i] == "" ):
        for j in range(8-len(ip)):
            s += ip[i].zfill(4)+":"
    s += ip[i].zfill(4)+":"
print(s.strip(":"))
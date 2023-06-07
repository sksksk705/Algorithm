import sys
si = sys.stdin.readline
tc = 1
while(True):
    s = list(si().strip())
    if s and s[0] == '-':
        break
    #스택
    st = []
    ans = 0
    for i in range(len(s)):
        if s[i] == '}':
            if len(st) == 0: #닫는 괄호가 매칭이 안 되면 스택에 넣는다.
                st.append('}')
            else:
                if st[len(st)-1] == '}':
                    ans += 1
                st.pop() #매칭 시키고 빼냄
        else:
            st.append('{') #여는 괄호는 스택에 넣어줌

    ans += len(st)//2
    if st and st[0] == '}': #닫는 괄호가 포함되어 있다면
        ans += 1

    print("{0}. {1}".format(tc,ans))
    tc += 1

# 위상정렬인거 같은데
# 어떻게 하더라?

# n = 20.

def solution(skill, skill_trees):
    answer = 0
    parent = [-1] * 26
    for i in range(1,len(skill)):
        parent[ord(skill[i])-ord('A')] = ord(skill[i-1])-ord('A')
    
    for skillset in skill_trees:
        learned = [0] * 26
        flag = 1
        for ski in skillset:
            # 부모스킬이 있는데 아직 안 익힌 상태라면
            if parent[ord(ski) - ord('A')] != -1 and learned[parent[ord(ski) - ord('A')]] == 0:
                    flag = 0
                    break
            learned[ord(ski)- ord('A')] = 1   
        if flag == 1:
            answer += 1
    return answer
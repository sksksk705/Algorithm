
def recursiveNum(numbers, idx, target, result):
    answer = 0
    if idx >= len(numbers):
        if result == target:
            return 1
        return 0
    answer += recursiveNum(numbers,idx+1,target,result + numbers[idx])
    answer += recursiveNum(numbers,idx+1,target,result - numbers[idx])
    return answer

def solution(numbers, target):
    answer = recursiveNum(numbers,0,target,0)
    return answer
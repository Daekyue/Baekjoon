import math
def solution(brown, yellow):
    answer = []
    hap = brown + yellow
    
    for i in range(2, hap//2):
        if (i-2) * ((hap//i) - 2) == yellow:
            answer.append(hap//i)
            answer.append(i)
            break
    
    return answer
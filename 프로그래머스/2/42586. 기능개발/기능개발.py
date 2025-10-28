# 하루에 speeds씩 증가 100 - progresses
# 그냥 100-로 해보기 # 애기랑 떠들고 싶당...
import math

def solution(progresses, speeds):
    answer = []
    days = [0] * len(progresses)
    
    for i in range(len(progresses)):
        rest = 100 - progresses[i]
        days[i] = math.ceil(rest / speeds[i])
    
    ans = 0
    compare = days[0]
    for i in days:
        if compare >= i:
            ans += 1
        else:
            answer.append(ans)
            compare = i
            ans = 1
    answer.append(ans)
        
    
    return answer




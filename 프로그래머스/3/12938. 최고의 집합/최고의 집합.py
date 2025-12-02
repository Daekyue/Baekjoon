def solution(n, s):
    answer = []
    
    if s < n:
        return [-1]
    
    mok = s // n
    na = s % n
    
    for _ in range(n - na):
        answer.append(mok)
    
    for _ in range(na):
        answer.append(mok+1)
    
    return answer
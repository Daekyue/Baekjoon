def solution(s):
    lst = list(map(int, s.split()))
    a = max(lst)
    b = min(lst)
    
    answer = f"{b} {a}"

    return answer
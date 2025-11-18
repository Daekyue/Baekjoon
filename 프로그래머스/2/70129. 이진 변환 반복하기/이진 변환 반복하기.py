def solution(s):
    delete = 0
    turn = 0
    s = list(map(int,s))
    
    while len(s) != 1:
        turn += 1
        leng = len(s)
        s = list(map(int,s))
        sm = sum(s)
        delete += leng - sm
        
        
        # 2진 변환
        s.clear()
        
        
        while sm != 1:
            s.append(sm % 2)
            sm = sm // 2
        s.append(1)
    
    return [turn, delete]
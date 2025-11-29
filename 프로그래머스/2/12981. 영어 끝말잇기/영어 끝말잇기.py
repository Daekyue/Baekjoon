def solution(n, words):
    answer = []
    dic = dict()
    words.insert(0, words[0][0])
    for idx, value in enumerate(words):
        if len(value) == 1:
            continue
        if value[0] != words[idx-1][-1]:
            if idx % n == 0:
                return [n,idx//n]
            else:
                return [idx%n, idx//n+1]
        else:
            try:
                dic[value]
                if idx % n == 0:
                    return [n,idx//n]
                else:
                    return [idx%n, idx//n+1]    
            except:
                dic[value] = 1
    return [0, 0]
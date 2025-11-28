def solution(elements):
    ans = set()
    leng = len(elements)
    elements += elements
    
    for i in range(1, leng+1):
        for j in range(leng):
            ans.add(sum(elements[j:j+i]))
    
    return(len(ans))
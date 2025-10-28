def solution(s):
    answer = True
    st = []
    for i in s:
        if i == '(':
            st.append(1)
        elif st and i == ')':
            st.pop()
        else:
            answer = False
            break
    
    if st:
        answer = False
    return answer
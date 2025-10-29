s = input()
lst = list(s)
st = []

answer = 0
for i in range(len(lst)):
    if lst[i] == '(':
        st.append(i)
    else:
        if lst[i-1] == '(':
            st.pop()
            answer += len(st)
        else:
            st.pop()
            answer +=1
print(answer)
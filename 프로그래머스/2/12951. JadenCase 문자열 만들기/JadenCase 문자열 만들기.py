def solution(s):
    answer = ''
    for i in range(len(s)):
        if i == 0 and 'a' <= s[0] <= 'z':
            answer += s[0].upper()
        elif i-1 >= 0 and s[i-1] == ' ' and 'a' <= s[i] <= 'z':
            answer += s[i].upper()
        elif 'A' <= s[i] <= 'Z' and i-1 >= 0 and s[i-1] != ' ':
            answer += s[i].lower()
        else:
            answer += s[i]

    return answer
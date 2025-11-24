def solution(people, limit):
    answer = 0
    people.sort()
    # 투포인터
    st = 0
    end = len(people)-1
    
    while st < end:
        if people[st] + people [end] <= limit:
            st += 1
            end -= 1
        elif people[st] + people [end] > limit:
            end -= 1
        answer += 1
    if st == end:
        answer += 1
    return answer
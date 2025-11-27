def solution(want, number, discount):
    answer = 0
    want_len = len(discount)

    for start in range(want_len - 9):
        dic = {}
        for i in range(10):
            item = discount[start + i]
            if item not in want:
                break
            dic[item] = dic.get(item, 0) + 1
            if dic[item] > number[want.index(item)]:
                break
        else:
            answer += 1

    return answer

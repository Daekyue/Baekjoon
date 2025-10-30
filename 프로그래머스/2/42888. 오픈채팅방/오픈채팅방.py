from collections import deque

def solution(record):
    answer = []
    dic = dict()
    q = deque()
    for i in record:
        lst = list(i.split())
        if lst[0] == 'Enter':
            q.append((lst[0], lst[1]))
            dic[lst[1]] = lst[2]
        elif lst[0] == 'Leave':
            q.append((lst[0], lst[1]))
        else:
            dic[lst[1]] = lst[2]
    
    while q:
        com, uid = q.popleft()
        if com == "Enter":
            answer.append(f"{dic[uid]}님이 들어왔습니다.")
        else:
            answer.append(f"{dic[uid]}님이 나갔습니다.")

    return answer
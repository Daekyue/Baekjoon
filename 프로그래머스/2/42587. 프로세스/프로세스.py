from collections import deque

def solution(priorities, location):
    q = deque((p, i) for i, p in enumerate(priorities))
    printed = 0

    while q:
        p, i = q.popleft()
        for p2, _ in q:
            if p2 > p:
                q.append((p, i))
                break
        else:                    
            printed += 1
            if i == location:
                return printed

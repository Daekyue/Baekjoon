import heapq

def solution(n, works):
    if sum(works) <= n:
        return 0
    
    # 최대 힙처럼 쓰기 위해 음수로 변환해서 heap에 넣기
    pq = [-w for w in works]
    heapq.heapify(pq)
    
    for _ in range(n):
        max_work = -heapq.heappop(pq)
        if max_work == 0:
            heapq.heappush(pq, 0)
            break
        max_work -= 1
        heapq.heappush(pq, -max_work)

    return sum(x * x for x in pq)

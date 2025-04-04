def solve_firefly(n, h, heights):
    bottom = [0] * (h + 1)  # 석순
    top = [0] * (h + 1)     # 종유석
    
    # 석순과 종유석을 구분하여 카운트
    for i in range(n):
        if i % 2 == 0:
            bottom[heights[i]] += 1
        else:
            top[heights[i]] += 1
    
    # 누적합 계산 (아래에서 위로 올라가며)
    for i in range(h-1, 0, -1):
        bottom[i] += bottom[i+1]
        top[i] += top[i+1]
    
    min_obstacle = n  # 최소 장애물 수 초기화
    cnt = 0  # 최소 장애물을 만나는 구간 수
    
    for i in range(1, h+1):
        total = bottom[i] + top[h - i + 1]
        
        if total < min_obstacle:
            min_obstacle = total
            cnt = 1
        elif total == min_obstacle:
            cnt += 1
    
    return min_obstacle, cnt

n, h = map(int, input().split())
heights = [int(input()) for _ in range(n)]

min_obstacle, cnt = solve_firefly(n, h, heights)
print(min_obstacle, cnt)

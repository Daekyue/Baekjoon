# 다음으로 밟을 수 있는 디딤돌이 여러 개인 경우 무조건 가장 가까운 디딤돌
# 한 번에 건너뛸 수 있는 디딤돌의 최대 칸수 k
# 연속 k개만큼 0인 디딤돌이 생기면 끝 몇 번 진행해야 하는가

def can(m, stones, k):
    cnt = 0
    for s in stones:
        if s < m:            # m번째 사람 오기 전 이미 0이 되는 돌
            cnt += 1
            if cnt >= k:     
                return False
        else:
            cnt = 0
    return True              

def solution(stones, k):
    lo, hi = 0, max(stones) 
    while lo < hi:
        mid = (lo + hi + 1) // 2   # 상향 이분 (가능한 쪽으로 당김)
        if can(mid, stones, k):
            lo = mid               
        else:
            hi = mid - 1          
    return lo
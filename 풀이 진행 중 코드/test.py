'''
 1. 유물 획득 가치가 가장 높은 경우
 2. 회전한 각도가 가장 작은 방법
 3. 회전 중심의 좌표의 열(x)가 가장 작은 구간, 열이 같다면 행이(y)가 가장 작은 구간

point가 채워지는건 x가 가장 크고 y가 가장 작은 값부터
완전 탐색..?

'''


def rotate():
    pass


def count_clear():
    pass


k, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(5)]
point = list(map(int, input().split()))

for _ in range(k): # k턴을 진행(유물이 없는 경우 즉시 종료)
    # [1] 탐사 진행
    mx_cnt = 0
    for rot in range(1, 4):     # 우선순위는 회전 수 -> 열 -> 행(작은순)
        for sj in range(3):
            for si in range(3):
                # rot 횟수만큼 90도 시계방향 회전 => narr에 넣기
                narr = [x[:] for x in arr] # 복사
                for _ in range(rot):
                    narr = rotate(narr, si, sj)

                # 유물갯수 카운트
                t = count_clear(narr, 0)
                if t > mx_cnt:                  # 최대 갯수수
                    mx_cnt = t
                    marr = narr
    # 유물이 없는 경우 턴 즉시 종료
    if mx_cnt == 0:
        break       # 탐사 즉지 종료

    #[2] 연쇄획득
    cnt = 0
    arr = marr
    while True:
        t = count_clear(arr, 1)

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# ro_d 0은 북쪽, 1은 동쪽, 2는 남쪽, 3은 서쪽 / 반시계 회전 = 현재 d +3 %4
n, m = map(int, input().split())
ro_i, ro_j, ro_d = map(int, input().split())
lst = [list(map(int, input().split())) for _ in range(n)]

state = True
count = 0
while (state): # 0은 쓰레기 있는 칸, 1은 벽, -1은 청소한 칸
    # 현재 칸 청소
    clean = True
    if lst[ro_i][ro_j] == 0:
        lst[ro_i][ro_j] = -1
        count += 1

    # 주변 4칸 청소 가능한지 체크
    # 주변 4칸 중 한 칸이 청소 가능한 칸인 경우
    # 현재 바라보는 방향에서 청소가능한 칸이 나올때까지 반시계 90도 돌린다
    # 한칸 전진
    for x in range(4):
        ni = ro_i + dx[(ro_d +3 -x) % 4]
        nj = ro_j + dy[(ro_d +3 -x) % 4]
        
        if 0 <= ni < n and 0 <= nj < m:
            if lst[ni][nj] == 0:
                ro_i = ni
                ro_j = nj
                ro_d = (ro_d +3 -x) % 4
                clean = False
                break
        
    # 주변 4칸 청소 불가능한 경우
    # 바라보는 방향 유지한채(전에 이동했던 방향, 한 칸 후진 후 다시 제일 위로, 만일 후진 불가능이라면 종료)
    if clean:
        ni = ro_i + dx[(ro_d +2) % 4]
        nj = ro_j + dy[(ro_d +2) % 4]
        if 0 <= ni < n and 0 <= nj < m and lst[ni][nj] != 1:
            ro_i = ni
            ro_j = nj
        else:
            state = False
            
print(count)
N = int(input())
arr = []
for _ in range(N):
    l, h = map(int, input().split())
    arr.append((l, h))
arr.sort()   # L 기준 오름차순 정렬

# 1) 최고 높이를 찾고, 그 기둥들의 가장 왼쪽/오른쪽 인덱스를 구한다.
max_h = 0
for _, h in arr:
    if h > max_h:
        max_h = h

# 최고 높이 기둥들의 인덱스 리스트
max_indices = [i for i, (_, h) in enumerate(arr) if h == max_h]
left_max_idx  = max_indices[0]
right_max_idx = max_indices[-1]

area = 0

# 2) 왼쪽 끝(0)부터 left_max_idx까지 스윕
current_h = arr[0][1]
for i in range(0, left_max_idx):
    # i번 기둥 높이가 더 높으면 갱신
    if arr[i][1] > current_h:
        current_h = arr[i][1]
    width = arr[i+1][0] - arr[i][0]
    area += current_h * width
    # 다음 기둥에서 더 높다면, 다시 갱신
    if arr[i+1][1] > current_h:
        current_h = arr[i+1][1]

# 3) 오른쪽 끝(N-1)부터 right_max_idx까지 역방향 스윕
current_h = arr[N-1][1]
for i in range(N-1, right_max_idx, -1):
    if arr[i][1] > current_h:
        current_h = arr[i][1]
    width = arr[i][0] - arr[i-1][0]
    area += current_h * width
    if arr[i-1][1] > current_h:
        current_h = arr[i-1][1]

# 4) “가장 높은 기둥 구간”을 채우기
L_left  = arr[left_max_idx][0]
L_right = arr[right_max_idx][0]
middle_width = L_right - L_left
area += max_h * middle_width

# 5) 여기까지 계산한 area에는,
#    - 왼쪽 스윕·오른쪽 스윕 구간(양쪽에서 최고 기둥까지 채운 넓이)
#    - 최고 기둥들 사이(왼쪽 최고 기둥 좌표 ~ 오른쪽 최고 기둥 좌표) 평탄화한 넓이
#    만 들어가 있다.
#    하지만, **정작 “가장 높은 기둥” 자체의 폭(=1)만큼은 아직 빠진 상태**이므로,
#    높이 max_h를 한 번 더해 주어야 합니다.

print(area + max_h)
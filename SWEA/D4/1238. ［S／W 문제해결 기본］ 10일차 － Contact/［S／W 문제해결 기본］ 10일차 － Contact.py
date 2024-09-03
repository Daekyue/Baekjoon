from collections import deque

T = 10
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    arr_num, start = map(int, input().split())

    arr = list(map(int, input().split()))
    arr_100 = [0] * 102

    visited = [0] * 101
    count = 0

    for i in range(0, arr_num-1, 2):
        if arr_100[arr[i]] == 0:
            arr_100[arr[i]] = [arr[i+1]]
        else:
            arr_100[arr[i]] = arr_100[arr[i]] + [arr[i+1]]

    q = deque()
    next_q = deque()
    next_q.append(arr_100[start])

    while next_q:
        q = next_q.copy()
        next_q = deque()
        count += 1
        while q:
            c = q.pop()
            while c:
                idx = c.pop()
                if not visited[idx]:
                    next_q.append(arr_100[idx])
                    visited[idx] = [idx, count]

    max_idx = -1
    max_count = -1

    for v in visited:
        if v != 0:  # 초기값이 0인 것을 제외하기 위함
            idx, cnt = v
            if cnt > max_count or (cnt == max_count and idx > max_idx):
                max_count = cnt
                max_idx = idx

    print(f'#{test_case} {max_idx}')
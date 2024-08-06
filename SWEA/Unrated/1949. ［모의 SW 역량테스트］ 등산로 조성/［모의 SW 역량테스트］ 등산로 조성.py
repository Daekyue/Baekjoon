# 방향 벡터: 우, 하, 좌, 상
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def dfs(x, y, height, cut, length, visited):
    global answer
    answer = max(answer, length)

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        if visited[nx][ny]:
            continue
        if arr[nx][ny] < height:  # 다음 지점이 현재 지점보다 낮은 경우
            visited[nx][ny] = True
            dfs(nx, ny, arr[nx][ny], cut, length + 1, visited)
            visited[nx][ny] = False
        elif cut and arr[nx][ny] - k < height:  # 깎아서 갈 수 있는 경우
            visited[nx][ny] = True
            dfs(nx, ny, height - 1, False, length + 1, visited)
            visited[nx][ny] = False


T = int(input())
for test_case in range(1, T + 1):
    n, k = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]

    max_value = 0
    max_pos = []
    answer = 0

    # 가장 높은 봉우리 찾기
    for i in range(n):
        for j in range(n):
            if max_value < arr[i][j]:
                max_value = arr[i][j]
                max_pos = [(i, j)]
            elif max_value == arr[i][j]:
                max_pos.append((i, j))

    # 각 봉우리에서 DFS 탐색 시작
    for pos in max_pos:
        visited = [[False] * n for _ in range(n)]
        x, y = pos
        visited[x][y] = True
        dfs(x, y, arr[x][y], True, 1, visited)

    print(f'#{test_case} {answer}')

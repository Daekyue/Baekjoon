from collections import deque

# 4-directional movement (right, down, left, up)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def mark_outside_air():
    air = [[0]*M for _ in range(N)]
    visited = [[False]*M for _ in range(N)]
    q = deque()
    q.append((0, 0))
    visited[0][0] = True
    air[0][0] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny]:
                if arr[nx][ny] == 0:
                    visited[nx][ny] = True
                    air[nx][ny] = 1
                    q.append((nx, ny))
                elif arr[nx][ny] == 1:
                    # Cheese cell; mark as visited to avoid rechecking
                    visited[nx][ny] = True
    return air

# Input
N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

time = 0
while True:
    air = mark_outside_air()
    melt = []
    # Find cheese cells to melt
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 1:
                count = 0
                for k in range(4):
                    ni = i + dx[k]
                    nj = j + dy[k]
                    if 0 <= ni < N and 0 <= nj < M:
                        if air[ni][nj] == 1:
                            count += 1
                if count >= 2:
                    melt.append((i, j))
    if not melt:
        print(time)
        break
    for x, y in melt:
        arr[x][y] = 0
    time += 1

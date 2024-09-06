from collections import deque

# 방향을 나타내는 4개의 벡터 (동, 북, 서, 남)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# 입력 받기
w, h = map(int, input().split())
arr = [list(input().strip()) for _ in range(h)]

# 레이저 위치 찾기 ('C'의 위치)
points = []
for i in range(h):
    for j in range(w):
        if arr[i][j] == 'C':
            points.append((i, j))

start_x, start_y = points[0]
end_x, end_y = points[1]

# 큐와 방문 배열 초기화
q = deque()
visited = [[[float('inf')] * 4 for _ in range(w)] for _ in range(h)]

# BFS 시작: 4방향 모두 큐에 넣기
for d in range(4):
    nx, ny = start_x + dx[d], start_y + dy[d]
    if 0 <= nx < h and 0 <= ny < w and arr[nx][ny] != '*':
        q.append((nx, ny, d))
        visited[nx][ny][d] = 0

# BFS 탐색
while q:
    x, y, d = q.popleft()

    # 목적지에 도착했으면 거울의 개수 출력
    if (x, y) == (end_x, end_y):
        print(min(visited[x][y]))  # 4방향 중 최소값 출력
        break

    # 같은 방향으로 쭉 이동
    nx, ny = x + dx[d], y + dy[d]
    if 0 <= nx < h and 0 <= ny < w and arr[nx][ny] != '*' and visited[nx][ny][d] > visited[x][y][d]:
        visited[nx][ny][d] = visited[x][y][d]
        q.appendleft((nx, ny, d))  # 같은 방향은 우선적으로 탐색

    # 방향을 바꿔서 이동 (거울 설치)
    for nd in range(4):
        if d != nd:
            nx, ny = x + dx[nd], y + dy[nd]
            if 0 <= nx < h and 0 <= ny < w and arr[nx][ny] != '*' and visited[nx][ny][nd] > visited[x][y][d] + 1:
                visited[nx][ny][nd] = visited[x][y][d] + 1
                q.append((nx, ny, nd))  # 방향 바꾸기

from collections import deque

move = ((-1, 0), (1, 0), (0, -1), (0, 1))


def bfs():
    global queue

    while queue:
        y, x = queue.popleft()
        for dy, dx in move:
            ny, nx = y+dy, x+dx
            if 0 <= ny < N and 0 <= nx < M:
                if tomato_location[ny][nx] == 0:
                    tomato_location[ny][nx] = tomato_location[y][x] + 1
                    queue.append((ny, nx))


M, N = list(map(int, input().split()))

tomato_location = [list(map(int, input().split())) for _ in range(N)]
queue = deque([])
for y in range(N):
    for x in range(M):
        if tomato_location[y][x] == 1:
            queue.append((y,x))

bfs()

result = 0
pan = 0
for q in range(N):
    for w in range(M):
        if tomato_location[q][w] == 0:
            pan = 1
            break
        else:
            result = max(result, tomato_location[q][w])
    if pan == 1:
        break

if pan == 1:
    print(-1)
else:
    print(result-1)
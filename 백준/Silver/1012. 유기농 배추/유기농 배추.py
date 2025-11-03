from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs(y, x):
    q = deque()
    q.append((y,x))
    visit[y][x] = 1

    while q:
        cy, cx = q.popleft()
        
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]

            if 0 <= ny < n and 0 <= nx < m:
                if not visit[ny][nx] and lst[ny][nx]:
                    q.append((ny, nx))
                    visit[ny][nx] = 1


T = int(input())

for _ in range(T):
    m, n, k = map(int, input().split())
    lst = [[0] * m for __ in range(n)]
    visit = [[0] * m for __ in range(n)]
    one_l = []
    answer = 0

    for i in range(k):
        x, y = map(int, input().split())
        lst[y][x] = 1
        one_l.append((y,x))
    
    for i in one_l:
        y = i[0]
        x = i[1]
        if not visit[y][x]:
            bfs(y, x)
            answer += 1
    print(answer)

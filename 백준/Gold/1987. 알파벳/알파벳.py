dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

r, c = map(int, input().split())
board = [list(input()) for _ in range(r)]

answer = 1
visit = [0] * 26  # 알파벳은 26개니까!

def dfs(x, y, cnt):
    global answer
    answer = max(answer, cnt)
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < r and 0 <= ny < c and visit[ord(board[nx][ny]) - ord('A')] == 0:
            visit[ord(board[nx][ny]) - ord('A')] = 1
            dfs(nx, ny, cnt + 1)
            visit[ord(board[nx][ny]) - ord('A')] = 0

visit[ord(board[0][0]) - ord('A')] = 1
dfs(0, 0, 1)
print(answer)

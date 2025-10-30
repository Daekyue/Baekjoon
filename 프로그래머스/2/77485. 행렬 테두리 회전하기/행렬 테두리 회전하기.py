def solution(rows, columns, queries):
    # 초기 행렬
    grid = [[r * columns + c + 1 for c in range(columns)] for r in range(rows)]
    answer = []

    for x1, y1, x2, y2 in queries:
        # 0-index 변환
        x1 -= 1; y1 -= 1; x2 -= 1; y2 -= 1

        prev = grid[x1][y1]          # 시작점 값 보관
        mn = prev                    # 이동한 값들 중 최소

        # 위쪽 행 (왼→오)
        for y in range(y1 + 1, y2 + 1):
            grid[x1][y], prev = prev, grid[x1][y]
            mn = min(mn, grid[x1][y])

        # 오른쪽 열 (위→아래)
        for x in range(x1 + 1, x2 + 1):
            grid[x][y2], prev = prev, grid[x][y2]
            mn = min(mn, grid[x][y2])

        # 아래쪽 행 (오→왼)
        for y in range(y2 - 1, y1 - 1, -1):
            grid[x2][y], prev = prev, grid[x2][y]
            mn = min(mn, grid[x2][y])

        # 왼쪽 열 (아래→위)
        for x in range(x2 - 1, x1 - 1, -1):
            grid[x][y1], prev = prev, grid[x][y1]
            mn = min(mn, grid[x][y1])

        answer.append(mn)

    return answer

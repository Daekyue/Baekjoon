n = 0


def can_build_runway(heights, m):
    global n
    used = [False] * n

    for i in range(n - 1):
        if heights[i] == heights[i + 1]:
            continue

        # 높이 차이가 1인 경우에만 경사로 설치 가능
        elif abs(heights[i] - heights[i + 1]) == 1:
            if heights[i] < heights[i + 1]:  # 올라가는 경사로
                for j in range(m):           # 경사로의 가로 길이 범위 안에서 비교를 진행하는데 경사로가 범위를 벗어나거나 이전의 위치에 경사로를 사용했거나 경사로를 설치할 곳이 일자가 아닌 경우
                    if i - j < 0 or used[i - j] or heights[i] != heights[i - j]:
                        return False
                    used[i - j] = True
            else:  # 내려가는 경사로
                for j in range(1, m + 1):
                    if i + j >= n or used[i + j] or heights[i + 1] != heights[i + j]:
                        return False
                    used[i + j] = True
        else:  # 높이 차이가 1 이상인 경우
            return False
    return True


def main():
    global n
    T = int(input())
    for test_case in range(1, T + 1):
        n, m = map(int, input().split())
        arr = [list(map(int, input().split())) for _ in range(n)]

        count = 0
        # 가로 방향 검사
        for i in range(n):
            if can_build_runway(arr[i], m):
                count += 1
            column = [arr[j][i] for j in range(n)]
            if can_build_runway(column, m):
                count += 1

        print(f"#{test_case} {count}")


if __name__ == "__main__":
    main()

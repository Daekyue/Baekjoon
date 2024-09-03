T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n = int(input())
    arr = []
    visited = [False] * n
    answer = 0

    for i in range(n):
        arr.append(int(input()) - 1)

    for i in range(1, n):
        if visited[i]:
            continue
        answer += 1
        for j in range(i, n):
            if arr[j] % arr[i] == 0:
                visited[j] = True

    print(f'#{test_case} {answer}')

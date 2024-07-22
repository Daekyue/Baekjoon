T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    arr = [list(map(int,input()))for _ in range(N)]

    start_point = int(N/2)
    answer = 0

    # 중앙을 기준으로 위로 올라가면서 더하기
    for i in range(int(N/2)+1):
        for j in range(N - 2*i):
            answer += arr[start_point - i][j+i]
    # 중앙을 기준으로 아래로 내려가면서 더하기
    for i in range(int(N/2)+1):
        for j in range(N - 2*i):
            answer += arr[start_point + i][j+i]
    # 중복해서 더해진 가운데 줄 제거
    for i in range(N):
        answer -= arr[start_point][i]

    print(f'#{test_case} {answer}')
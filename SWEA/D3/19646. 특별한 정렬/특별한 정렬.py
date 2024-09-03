T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n = int(input())
    arr = list(map(int, input().split()))

    arr.sort()

    s_list = arr[0:n//2]
    l_list = arr[n//2:n]
    sum_list = []

    for i in range(n//2):
        sum_list.append(l_list[-i -1])
        sum_list.append(s_list[i])

    print(f'#{test_case} ', end="")
    for x in range(10):
        print(sum_list[x], end=" ")
    print("")



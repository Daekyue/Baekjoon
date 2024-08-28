import heapq
'''
N만큼 dict 다 선언하고
'''

def main():
    T = int(input())
    # 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    for test_case in range(1, T + 1):
        N, M = map(int, input().split())
        arr = list(map(int, input().split()))

        answer = 0
        dict_edge = {}
        for i in range(1, N+1):
            dict_edge[i] = [i]

        for i in range(M):
            flag = False
            a, b = arr[2*i], arr[2*i+1]
            if a > b:
                a, b = b, a

            temp_arr = dict_edge[a]
            temp_arr_b = dict_edge[b]

            while a not in temp_arr:
                a = temp_arr[0]
                temp_arr = dict_edge[a]

            while b not in temp_arr_b:
                b = temp_arr_b[0]
                temp_arr_b = dict_edge[b]
                flag = True

            if b in temp_arr:
                continue
            elif flag:
                dict_edge[a] = temp_arr + temp_arr_b
                dict_edge[b] = [a]
            else:
                dict_edge[a] = temp_arr + [b]
                dict_edge[b] = [a]

        for i in range(1, N+1):
            temp_arr = dict_edge[i]
            if i not in temp_arr:
                continue
            answer += 1

        print(f'#{test_case} {answer}')


if __name__ == "__main__":
    main()
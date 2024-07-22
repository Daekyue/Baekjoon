def recursion(n, m):
    if m == 1:
        return n
    else:
        return n * recursion(n, m-1)

def main():
    # 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    for test_case in range(10):
        Test = int(input())
        n, m = list(map(int, input().split()))
        answer = recursion(n, m)
        print(f'#{Test} {answer}')

main()
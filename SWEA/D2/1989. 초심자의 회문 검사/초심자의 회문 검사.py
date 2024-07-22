# import sys
# sys.stdin = open("input.txt", "r")

def recursion(str, length):
    if length == 1 or length == 0:
        return 1
    else:
        if (str[0] == str[-1]):
            return recursion(str[1:length - 1], length - 2)
        else:
            return 0

def main():
    T = int(input())
    # 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    for test_case in range(1, T + 1):
        str = input()

        answer = recursion(str, len(str))
        print(f'#{test_case} {answer}')

main()
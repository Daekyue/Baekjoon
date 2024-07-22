decode = [
    [3, 2, 1, 1], [2, 2, 2, 1], [2, 1, 2, 2], [1, 4, 1, 1], [1, 1, 3, 2],
    [1, 2, 3, 1], [1, 1, 1, 4], [1, 3, 1, 2], [1, 2, 1, 3], [3, 1, 1, 2]
]

def main():
    T = int(input())
    for test_case in range(1, T + 1):
        n, m = map(int, input().split())
        lines = [input().strip() for _ in range(n)]

        # 1이 포함된 마지막 줄에서 암호코드 추출
        str_code = ""
        for i in range(n - 1, -1, -1):
            if '1' in lines[i]:
                str_code = lines[i]
                break

        # 암호코드 끝부분부터 탐색
        pos = str_code.rfind('1') # rfind는 오른쪽에서 부터 탐색하는 것
        pos -= 55  # 암호코드는 56자리이므로, 처음 1이 나온 곳에서 55칸 앞으로 이동

        arr = [int(str_code[pos + i]) for i in range(56)] # 56자리 코드르 뽑아냄

        # 코드 해독
        solveNumArr = []
        for i in range(8):
            solve = [0] * 4
            solveNum = 0
            for j in range(7):
                solve[solveNum] += 1
                if j < 6 and arr[(i * 7) + j] != arr[(i * 7) + j + 1]:
                    solveNum += 1
            rowIndex = 0
            for k in range(10):
                if decode[k] == solve:
                    rowIndex = k
                    break
            solveNumArr.append(rowIndex)

        answer = 0
        sum_value = 0
        for i in range(8):
            if i % 2 == 0:
                sum_value += (solveNumArr[i] * 3)
            else:
                sum_value += solveNumArr[i]
            answer += solveNumArr[i]

        if sum_value % 10 != 0:
            answer = 0

        print(f"#{test_case} {answer}")

if __name__ == "__main__":
    main()

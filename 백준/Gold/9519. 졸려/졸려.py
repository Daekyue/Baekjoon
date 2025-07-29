# 몇번을 반복하면 원상태로 돌아오는지 횟수 체크
# 횟수 체크 완료 후 그 횟수만큼 나눈 나머지만큼 for문 진행

def counting(abc):
    count = 0
    arr = []
    while True:
        start = 0
        end = len(abc) - 1
        newabc = ""
        while start < end:
            newabc += abc[start] + abc[end]
            start += 1
            end -= 1
        if len(abc) % 2 == 1:
            newabc += abc[start]
        if newabc in arr:
            break
        arr.append(newabc)
        abc = newabc
        count += 1

    return count

def recovery(N, abc):
    for _ in range (N) :
        start = 0
        end = len(abc) - 1
        newabc = ""
        while start < end:
            newabc += abc[start] + abc[end]
            start += 1
            end -= 1
        if len(abc) % 2 == 1:
            newabc += abc[start]

        abc = newabc

    return abc

N = int(input())
abc = input()

recur = counting(abc)
N %= recur
answer = recovery(recur-N, abc)

print(answer)
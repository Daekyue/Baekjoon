N = int(input())
arr = list(map(int, input().split()))
M = int(input())
arr2 = list(map(int, input().split()))

arr.sort()

def func(start, mid, end, target):
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return 1
        elif arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return 0
    

for i in arr2:
    start = 0
    mid = N//2
    end = N-1
    print(func(start, mid, end, i))

        
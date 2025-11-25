# 유클리드 호제법 (A, B) => (B, A % B)
# 하나씩 하나씩 진행하는 방법
def func(a,b):
    x, y = a, b
    while x % y != 0:
        temp = x
        x = y
        y = temp%y
        
    return int(a*b/y)

def solution(arr):
    answer = 0
    arr.sort()
    for i in range(len(arr)-1):
        arr[i+1] = func(arr[i+1], arr[i])
        
    return arr[-1]
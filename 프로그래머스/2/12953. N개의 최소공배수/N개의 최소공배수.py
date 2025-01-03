# 최소공배수 = 두 수의 곱 // 최대공약수
def func(a, b):
    ta, tb = a, b
    while b > 0:
        a, b = b, a % b
    
    maxdiv = a
    
    return ta * tb // maxdiv

def solution(arr):
    arr.sort()
    answer = arr[0]
    for i in range (len(arr)-1):
        answer = func(answer, arr[i+1])
    return answer
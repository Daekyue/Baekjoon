def solution(n):
    if n == 1:
        return 1
    ans = [0] * (n+1)
    ans[1] = 1
    ans[2] = 2
    if n >= 3:
        for i in range(3,n+1):
            ans[i] = ans[i-2] + ans[i-1]
    
    return ans[n] % 1234567
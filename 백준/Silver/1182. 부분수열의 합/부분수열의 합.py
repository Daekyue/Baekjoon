def func(k, total, cnt):
    global answer
    if k == n:
        if total == s and cnt != 0:
            answer += 1
        return
    func(k+1, total, cnt)
    func(k+1, total+arr[k], cnt+1)
    


n, s = map(int, input().split())
arr = list(map(int, input().split()))
answer = 0


func(0,0,0)
print(answer)
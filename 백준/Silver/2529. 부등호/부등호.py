def trans(cur):
    global mn, mx
    res = 0
    je = len(cur)-1
    for i in cur:
        res += i * (10 ** je)
        je -= 1
    mn = min(res, mn)
    mx = max(res, mx)
    return 

def func(step, cur):
    if step >= n:
        trans(cur)
        return
    for i in range(10):
        if i not in cur:
            if (lst[step] == '<' and cur[step] < i) or (lst[step] == '>' and cur[step] > i):
                cur.append(i)
                func(step+1, cur)
                cur.pop()
                
    return 0

n = int(input())
lst = list(input().split())
mn, mx = 10**10, 0


for i in range(10):
    cur = []
    cur.append(i)
    func(0, cur)

print(mx)
if mn < 10**n:
    zero = '0'
    print(f'0{mn}')
else:
    print(mn)
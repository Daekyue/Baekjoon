def dfs(idx, cur, plus, minus, mul, div):
    global mx, mn

    if idx == n:  # 숫자 n개를 모두 사용 완료
        mx = max(mx, cur)
        mn = min(mn, cur)
        return

    x = a[idx]

    if plus:
        dfs(idx + 1, cur + x, plus - 1, minus, mul, div)

    if minus:
        dfs(idx + 1, cur - x, plus, minus - 1, mul, div)

    if mul:
        dfs(idx + 1, cur * x, plus, minus, mul - 1, div)

    if div:
        if cur < 0:
            dfs(idx + 1, -(-cur // x), plus, minus, mul, div - 1)
        else:
            dfs(idx + 1, cur // x, plus, minus, mul, div - 1)


n = int(input())
a = list(map(int, input().split()))
plus, minus, mul, div = map(int, input().split())

mx = -10**9
mn = 10**9

dfs(1, a[0], plus, minus, mul, div)

print(mx)
print(mn)

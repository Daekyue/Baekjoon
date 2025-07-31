N = int(input())

# 가정: N은 배달해야 할 무게
INF = 10**9
dp = [INF] * (N+1)
dp[0] = 0  # 0kg 만드는 데는 봉지 0개

for i in range(1, N+1):
    # 3kg 봉지를 쓸 수 있으면
    if i >= 3 and dp[i-3] != INF:
        dp[i] = min(dp[i], dp[i-3] + 1)
    # 5kg 봉지를 쓸 수 있으면
    if i >= 5 and dp[i-5] != INF:
        dp[i] = min(dp[i], dp[i-5] + 1)

# 결과 확인
if dp[N] == INF:
    print(-1)
else:
    print(dp[N])


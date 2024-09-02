N = int(input())
counsel = [list(map(int, input().split())) for _ in range(N)]

cost = [0] * (N+2)

for i in range(1, len(counsel)+1):
    T = counsel[i-1][0]
    P = counsel[i-1][1]

    if T+i <= N+1:
        cost[i+T] = max(cost[i+T], max(cost[:i+1])+P)
    else:
        continue

print(max(cost))
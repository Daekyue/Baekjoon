from itertools import combinations

def cal(home, chi):
    home_x, home_y = home
    chi_x, chi_y = chi
    return (abs(home_x - chi_x) + abs(home_y - chi_y))

n, m = map(int, input().split())
lst = [list(map(int, input().split())) for _ in range(n)]

homes = []
chis = []

for i in range(n):
    for j in range(n):
        if lst[i][j] == 1:
            homes.append((i,j))
        elif lst[i][j] == 2:
            chis.append((i,j))

if len(chis) <= m:
    ans = [9999] * len(homes)
    for idx, home in enumerate(homes):
        for chi in chis:
            rst = cal(home, chi)
            if ans[idx] > rst:
                ans[idx] = rst
                if rst == 1:
                    continue
    print(sum(ans))
else:
    cho_chis = list(combinations(chis, m))
    answer = 99999
    for chis in cho_chis:
        ans = [9999] * len(homes)
        for idx, home in enumerate(homes):
            for chi in chis:
                rst = cal(home, chi)
                if ans[idx] > rst:
                    ans[idx] = rst
                    if rst == 1:
                        continue
        if answer > sum(ans):
            answer = sum(ans)
    print(answer)
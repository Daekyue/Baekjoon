# 조합 뽑기
# 뽑은 조합 리스트에서 원소 개수가 2개인 순열 뽑기 진행
# 2개 뽑은 값의 합 구하고 minimum 값 초기화하면서 진행?
from itertools import combinations # 조합


n = int(input())
arr = [list(map(int, input().split())) for _ in range (n)]
lst = []

for i in range (n):
    lst.append(i)

mini = 999999
for team_a in combinations(lst, n // 2):
    rev_comb_lst = []
    rev_comb_lst = [i for i in lst if i not in team_a]
    
    a_sum = 0
    b_sum = 0

    for k in combinations(team_a, r=2):
        a_sum += arr[k[0]][k[1]] + arr[k[1]][k[0]]
    for k in combinations(rev_comb_lst, r=2):
        b_sum += arr[k[0]][k[1]] + arr[k[1]][k[0]]

    if abs(a_sum - b_sum) < mini:
        mini = abs(a_sum - b_sum)

print(mini)
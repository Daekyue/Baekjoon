# 한 줄안에 있는 애들 다 타고 들어가자
# 들어갔을 때 visit

def dfs(i, visit, computers, flag):
    for j in range(len(computers[i])):
        if computers[i][j] and not visit[j]:
            visit[j] = 1
            flag[0] = 1
            dfs(j, visit, computers, flag)
    
def solution(n, computers):
    answer = 0
    visit = [0] * n
    for i in range(n):
        flag = [0]
        dfs(i, visit, computers, flag)
        if flag[0]:
            answer += 1
    return answer
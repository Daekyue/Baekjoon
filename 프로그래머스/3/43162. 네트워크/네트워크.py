# 한 줄안에 있는 애들 다 타고 들어가자
# 들어갔을 때 visit

def dfs(i, visit, computers):
    for j in range(len(computers[i])):
        if computers[i][j] and not visit[j]:
            visit[j] = 1
            dfs(j, visit, computers)
    
def solution(n, computers):
    answer = 0
    visit = [0] * n
    for i in range(n):
        if not visit[i]:
            dfs(i, visit, computers)
            answer += 1
    return answer
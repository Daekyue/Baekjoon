from collections import deque

def bfs_cnt(start, er_i, er_j, graph,n):
    visit = [0] * (n+1)
    q = deque()
    q.append(start)
    visit[start] = 1
    cnt = 1
    while q:
        cur = q.popleft()
        for nxt in graph[cur]:
            if(cur != er_i or nxt != er_j) and (nxt != er_i or cur != er_j):
                if not visit[nxt]:
                    q.append(nxt)
                    visit[nxt] = 1
                    cnt += 1
    
    return abs(n - cnt *2)

def solution(n, wires):
    graph = [[] for i in range (n+1)]
    answer = 101
    for i, j in wires:
        graph[i].append(j)
        graph[j].append(i)
        
    for i,j in wires:
        answer = min(bfs_cnt(i,i,j,graph,n), answer)
    
    return answer
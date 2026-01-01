# 시뮬레이션 문제
# 그럼 칸이 연결되는건 어떻게 체크?
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

from collections import deque

def bfs(copy, ij, vis, div):
    q = deque()
    i, j = ij
    q.append((i,j))
    vis_n = vis[i][j]
    vis[i][j] = 0
    copy[i][j] = div
    
    while (q):
        c_i, c_j = q.popleft()
        
        for d in range(4):
            ni = c_i + dx[d]
            nj = c_j + dy[d]
            
            if 0 <= ni < n and 0 <= nj < n:
                if vis_n == vis[ni][nj]:
                    q.append((ni, nj))
                    copy[ni][nj] = div
                    vis[ni][nj] = -1
                    

def dfs(vis, i, j, count):
    st = []
    st.append((i,j))
    vis[i][j] = count
    sm = lst[i][j]
    cnt = 1
    
    while (st):
        c_i, c_j = st.pop()
        
        for d in range(4):
            ni = c_i + dx[d]
            nj = c_j + dy[d]
            
            if 0 <= ni < n and 0 <= nj < n:
                if not vis[ni][nj] and l <= abs(lst[c_i][c_j] - lst[ni][nj]) <= r:
                    st.append((ni, nj))
                    vis[ni][nj] = count
                    sm += lst[ni][nj]
                    cnt += 1
    
    if sm == lst[i][j]:
        return (0, (i,j))
    return (sm // cnt, (i,j))
        

n, l, r = map(int, input().split())
lst = [list(map(int, input().split())) for _ in range(n)]
state = True
ans = -1
while (state):
    # 국경 열리는지 로직 (2중 for문)
    state = False
    ans += 1
    vis = [[0]*n for _ in range(n)]
    copy = [q[:] for q in lst]
    count = 1
    for i in range(n):
        for j in range(n):
            if vis[i][j] == 0:
                div, ij = dfs(vis, i, j, count)
                # lst 복사본을 하나 만들어서 그 복사본에 옮겨 놓고 for문 다 돌고 나서 옮기는 방식으로 진행해야 할듯
                # 한 뭉텅이 옮기고 다음 뭉텅이 옮겨야할 때 그 앞에 뭉텅이가 이미 바뀌어 있어서 문제 생기는 것 같음
                if div:
                    bfs(copy, ij, vis, div)
                    state = True
            count += 1
    lst = [q[:] for q in copy]
    
print(ans)

# 3 5 10
# 1 4 9
# 6 1 4
# 1 5 1
#
# 2 5 5
# 2 2 5
# 2 5 1

# n이 50 = 또 그냥... 다 뒤져봐야지 머,..
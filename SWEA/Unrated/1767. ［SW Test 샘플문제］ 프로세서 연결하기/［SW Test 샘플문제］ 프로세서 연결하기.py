dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def dfs(depth, total_length, core_count):
    global min_length, answer_max_core_count
    
    if answer_max_core_count < core_count:
        min_length = total_length
        answer_max_core_count = core_count
    elif answer_max_core_count == core_count:
        min_length = min(total_length, min_length)

    if depth == count:
        return
    
    for d in range(4):
        cur_x, cur_y = core_list[depth]
        nx, ny = cur_x, cur_y
        core_line = 0
        flag = False
        
        while 0 < nx < n-1 and 0 < ny < n-1:
            nx = nx + dx[d]
            ny = ny + dy[d]
            if arr[nx][ny] != 0:
                flag = True
                break
            core_line += 1
        
        if flag:
            continue
        
        nx, ny = cur_x, cur_y
        for i in range(core_line):
            nx = nx + dx[d]
            ny = ny + dy[d]
            arr[nx][ny] = 2
            
        dfs(depth+1, total_length + core_line, core_count + 1)
        
        while cur_x != nx or cur_y != ny:
            arr[nx][ny] = 0
            nx = nx - dx[d]
            ny = ny - dy[d]
    
    dfs(depth+1, total_length, core_count)

T = int(input())
for test_case in range(1, T + 1):
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]
    count = 0
    core_list = []
    min_length = 1234567
    answer_max_core_count = 0

    for i in range(1, n-1):
        for j in range(1, n-1):
            if arr[i][j] == 1:
                count += 1
                core_list.append((i, j))

    dfs(0, 0, 0)
    
    print(f'#{test_case} {min_length}')

dx = [0, 0, -1] # 사다리 게임을 역으로 올라갈 계획이기에 아래로 내려가는 x 좌표와 y좌표는 필요X
dy = [1, -1, 0] # 순서는 오른쪽 확인 왼쪽 확인 위쪽 확인 순으로 진행하였다. 사다리 게임의 특성 상 좌, 우가 모두 존재하는 경우는 없기에
# 좌우가 모두 존재하지 않을 경우 위로 올라간다.


# 문제에서 표현한 x좌표가 2차원 배열에서는 y값이 되고, 코드 상으로는 x의 값이 0일 경우 y의 값을 반환하는 방식의 코드르 구성할 예정

for test_case in range(10):
    T = int(input())
    
    ladders = [[0 for _ in range(100)] for _ in range(100)]
    for i in range(100):
        row = input().split()
        for j in range(100):
            ladders[i][j] = int(row[j])
            if(ladders[i][j] == 2):
                end_point = (i, j)

    x = int(end_point[0])
    y = int(end_point[1])
    last_move = 2

    while(x != 0): # i가 0일 경우 우로 이동, i가 1일 경우 좌로 이동, i가 2일 경우 위로 이동
        for i in range(3):
            if(last_move == 0 and i == 1):
                continue
            if(last_move == 1 and i == 0):
                continue
            nx = x + dx[i]
            ny = y + dy[i]
            if(nx >= 0 and nx < 100 and ny >= 0 and ny < 100):
                if(ladders[nx][ny] == 1):
                    last_move = i
                    x = nx
                    y = ny
                    break
    print(f'#{test_case+1} {y}')
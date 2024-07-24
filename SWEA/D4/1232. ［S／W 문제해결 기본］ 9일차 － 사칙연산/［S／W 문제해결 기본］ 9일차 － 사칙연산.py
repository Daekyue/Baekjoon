
def cal(node_num):
    if (len(tree[node_num])) == 2:      # 자식 노드가 없는 노드일 때
        return int(tree[node_num][1])
    else:
        left = cal(int(tree[node_num][2])) # 왼쪽 노드 들어가기
        right = cal(int(tree[node_num][3])) # 오른쪽 노드 들어가기
        
        if tree[node_num][1] == '+':
            return left + right
        elif tree[node_num][1] == '-':
            return left - right
        elif tree[node_num][1] == '*':
            return left * right
        elif tree[node_num][1] == '/':
            return left // right

T = 10
for test_case in range(1, T + 1):
    n = int(input())
    tree = [None] * (n+1)
    for i in range(n):
        str_input = input().split()
        tree[int(str_input[0])] = str_input
    
    answer = int(cal(1))
    
    print(f'#{test_case} {answer}')

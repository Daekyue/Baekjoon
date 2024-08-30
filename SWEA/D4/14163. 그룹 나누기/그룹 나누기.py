'''
find_set 함수: 이 함수는 x가 속한 집합의 대표(루트)를 찾는 역할을 하며, 
경로 압축을 통해 트리의 높이를 줄여 이후의 find_set 연산을 더 빠르게 만듭니다.
'''
def find_set(parent, x):
    # x가 속한 집합의 대표(루트)를 찾는 함수
    if parent[x] != x:
        parent[x] = find_set(parent, parent[x])  # 경로 압축: 중간 노드들이 직접 루트 노드를 가리키도록 함
    return parent[x]


'''
make_union 함수: 두 노드가 속한 집합을 하나로 합칩니다. 
루트가 다르면 랭크(rank)를 비교하여 트리를 합치고, 
랭크가 같을 경우 하나의 트리를 다른 트리에 연결하면서 랭크를 증가시킵니다.
'''
def make_union(parent, rank, x, y):
    # 두 노드 x와 y가 속한 집합을 합치는 함수
    root_x = find_set(parent, x)
    root_y = find_set(parent, y)
    
    # 두 루트가 다를 경우, 트리를 합침
    if root_x != root_y:
        if rank[root_x] > rank[root_y]:
            parent[root_y] = root_x  # 랭크가 작은 트리를 큰 트리에 연결
        elif rank[root_x] < rank[root_y]:
            parent[root_x] = root_y
        else:
            parent[root_y] = root_x  # 랭크가 같으면 하나의 트리를 다른 트리에 연결하고 랭크를 증가시킴
            rank[root_x] += 1

def main():
    T = int(input())  # 테스트 케이스의 개수를 입력받음
    for t in range(1, T+1):
        N, M = map(int, input().split())  # N: 학생 수, M: 조 신청서의 쌍 수
        pairs = list(map(int, input().split()))  # 조 신청서에서 받은 출석 번호 쌍들
        parent = list(range(N + 1))  # 각 학생의 부모를 자기 자신으로 초기화
        rank = [0] * (N + 1)  # 랭크를 0으로 초기화
        
        # 입력된 쌍들을 인접한 두 개씩 묶어 같은 조로 만듦
        for i in range(0, 2 * M, 2):
            x, y = pairs[i], pairs[i + 1]
            make_union(parent, rank, x, y)
        
        # 고유한 조의 수를 세기 위해 루트 노드들을 찾음
        unique_roots = set()
        for i in range(1, N + 1):
            unique_roots.add(find_set(parent, i))
        
        # 테스트 케이스 번호와 조의 개수를 출력
        print(f"#{t} {len(unique_roots)}")

main()
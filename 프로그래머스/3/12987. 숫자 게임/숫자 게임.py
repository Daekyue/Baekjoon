# A의 배열의 길이만큼 수행한다? A의 첫번째 원소보다 작은 값 = A의 제일 뒷 값과 붙도록, A의 첫 값보다 큰 값 중 제일 작은 값
# A의 두번재 원소보다 
# A의 i번째 원소보다 작은 B의 값은 다 0처리(사용처리) & A의 제일 큰 값 처리
# 투 포인트

def solution(A, B):
    A.sort()
    B.sort()
    
    a_pt = 0
    b_pt = 0
    answer = 0
    while a_pt < len(A) and b_pt < len(B):
        if A[a_pt] >= B[b_pt]:
            b_pt += 1
        else:
            a_pt += 1
            b_pt += 1
            answer += 1

    return answer

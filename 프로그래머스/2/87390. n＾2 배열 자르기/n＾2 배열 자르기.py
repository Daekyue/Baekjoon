# def solution(n, left, right):
#     answer = []
#     arr = [[1]*n for _ in range(n)]
    
#     for i in range(n):
#         for j in range(n):
#             if j+1 <= i+1:
#                 arr[i][j] = i+1
#             else:
#                 arr[i][j] = j+1

#     ans = []
#     for i in arr:
#         ans += i
    
#     return ans[left:right+1]

# # 1234 2234 3334 4444
def solution(n, left, right):
    answer = []
    for k in range(left, right + 1):
        i = k // n
        j = k % n
        answer.append(max(i, j) + 1)
    return answer

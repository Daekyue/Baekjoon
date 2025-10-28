def solution(arr):
    answer = []
    target = arr[0]
    answer.append(target)
    for i in range(1, len(arr)):
        if arr[i] != target:
            target = arr[i]
            answer.append(target)
    
    return answer


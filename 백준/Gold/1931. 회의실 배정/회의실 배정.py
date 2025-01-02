n = int(input())
arr = []

for i in range(0, n):
    start, end = map(int, input().split())
    arr.append((start, end))

arr.sort(key=lambda x: (x[1], x[0]))

endPoint = 0
answer = 0
for start, end in arr:
    if endPoint <= start:
        answer += 1
        endPoint = end

print(answer)
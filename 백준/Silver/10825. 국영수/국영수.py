n = int(input())

lst = []
for i in range(n):
    name, k, y, s = map(str, input().split())
    lst.append((name, int(k), int(y),int(s)))

lst.sort(key = lambda x:(-x[1], x[2], -x[3], x[0]))

for i in lst:
    print(i[0])
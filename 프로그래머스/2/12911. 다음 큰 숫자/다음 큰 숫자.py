def solution(n):
    target = bin(n).count('1')
    x = n + 1
    while True:
        if bin(x).count('1') == target:
            return x
        x += 1

# 글자 수 하나만 바뀌는지 체크 => 함수 check
# 글자 수 하나만 바뀌는 애들 다 시도

def dfs(cur, tar, words, root, ans):
    root.append(cur)
    if cur == tar:
        if ans[0] > len(root)-1:
            ans[0] = len(root) - 1
        return
    for i in words:
        if i in root:
            continue
        if check(cur, i):
            dfs(i, tar, words, root, ans)
            root.pop()

def check(begin, compare):
    chk = 0
    for i in range(len(begin)):
        if begin[i] != compare[i]:
            chk += 1
        if chk > 1:
            return False
    return True

def solution(begin, target, words):
    global dap
    if not target in words:
        return 0
    
    root = []
    ans = [99]
    dfs(begin, target, words,root, ans)
    
    return ans[0]
p = [-1] * 10005


def find(x):
    if p[x] < 0:
        return x
    p[x] = find(p[x])
    return p[x]


def is_diff_group(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return False
    if p[u] == p[v]:
        p[u] -= 1
    if p[u] < p[v]:
        p[v] = u
    else:
        p[u] = v
    return True


def main():
    v, e = map(int, input().split())
    edges = []
    for _ in range(e):
        a, b, cost = map(int, input().split())
        edges.append((cost, a, b))

    edges.sort()

    cnt = 0
    ans = 0
    for cost, a, b in edges:
        if not is_diff_group(a, b):
            continue
        ans += cost
        cnt += 1
        if cnt == v - 1:
            break

    print(ans)


if __name__ == "__main__":
    main()

ans = float('inf')
n = 10
f = open("salesman.in")
l = []
for i in range(10):
    l.append(f.readline().split())
p = [0 for i in range(10)]
used = [False for i in range(10)]

def count():
    c = 0
    for i in range(9):
        c+=l[p[i]][p[i+1]]
    return c


def rec(idx):
    global ans, l, p, used
    if (idx == n - 1):
        ans = min(ans, sum(p))
        print (ans)
        print(' '.join(map(str, p)))
        return
    for i in range(1, n):
        if (used[i]):
            continue
        p[idx] = i
        used[i] = True
        rec(idx+1)
        used[i] = False


rec(0)



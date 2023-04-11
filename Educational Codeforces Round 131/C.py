t = int(input())
for _ in range(t):
    n, m = map(int, input().split(' '))
    a = [int(i) - 1 for i in input().split(' ')]
    can = [0 for i in range(n)]
    for i in range(m):
        can[a[i]] += 1

    # проверка возвращаемого времени (подходит ли наим. величина под наши условия)
    def check(j):
        f, need = 0, 0
        for i in range(n):
            if j >= can[i]:
                f += (j - can[i]) // 2
            else:
                need += can[i] - j
        return need <= f

    # бинарный поиск
    l, r = 0, 2 * m
    res = -1
    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            res = mid
            r = mid - 1
        else:
            l = mid + 1
    print(res)

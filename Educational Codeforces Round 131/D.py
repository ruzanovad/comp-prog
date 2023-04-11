t = int(input())
for _ in range(t):
    n = int(input())
    B = [int(i) for i in input().split(' ')]
    S = []
    ans = [0 for i in range(n)]
    for i in range(n):
        S.append(((i+1)//(B[i]+1) + 1, i))
    S.sort()
    s = []
    j = 0
    for i in range(1, n+1):
        while j < n and S[j][0] == i:
            d = S[j][1]
            j += 1
            if B[d]:
                s.append(((d + 1) / B[d], d))
            else:
                s.append((n, d))
            s.sort()
        ans[s[0][1]] = i
        s.pop(0)
        s.sort()
    print(' '.join(map(str, ans)))


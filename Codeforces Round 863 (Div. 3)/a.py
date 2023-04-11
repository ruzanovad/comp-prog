def solve():
    n, d = [int(i) for i in input().split()]
    s = input()
    f = False
    b = []
    for i in range(n):
        if f:
            b.append(s[i])
        else: 
            if (ord(s[i]) - ord('0')< d):

                b.append(str(d))
                b.append(s[i])
                f = True
            else:
                b.append(s[i])
    if not f:
        b.append(str(d))
    print(''.join(b))

t  =int(input())
for _ in range(t):
    solve()

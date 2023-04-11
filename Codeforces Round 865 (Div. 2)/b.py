
def solve():
    n = int(input())
    a = [[0 for j in range(n)] for i in range(2)]
    a[0][0] = 2*n-1
    a[1][n-1] = 2*n
    a[0][n-1] = n
    a[1][0] = n-1
    for i in range((n-2)//2):
        a[0][1+2*i]=1 + 2*i
        a[1][1+2*i]=n+1 + 2*i
        a[0][2+2*i]=n+2 + 2*i
        a[1][2+2*i]=2 + 2*i

    for i in range(2):
        print(*a[i])
    





t  =int(input())
for _ in range(t):
    solve()

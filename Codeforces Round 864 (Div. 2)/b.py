
def solve():
    n, k= [int(i) for i in input().split()]
    a = ['' for i in range(n)]
    for i in range(n):
        a[i] = [int(i) for i in input().split()]
    c = 0
    f = 0
    for i in range(n//2):
        for j in range(n):
            if a[i][j] !=a[n-i-1][n-j-1]:
                c+=1
            f+=1
    # print(f)
    if n % 2:
        # for i in range(n//2):
        #     if a[i][n//2+1] !=a[n-i-1][n//2+1]:
        #         c+=1
        f = 0
        for j in range(n//2):
            if a[n//2][j] !=a[n//2][n-j-1]:
                c+=1
            f+=1
        # print(f)
        if (c <=k):
            print("YES")
        else:
            print("NO")

    else:
        if (c <=k):
            if (k-c)%2 == 0:
                print("YES")
            else:
                print("NO")
        else:
            print("NO")




t  =int(input())
for _ in range(t):
    solve()

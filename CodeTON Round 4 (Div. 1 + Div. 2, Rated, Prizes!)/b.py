def solve():
    n = int(input())
    a = [int(i) for i in input().split()]
    for i in range(n):
        for j in range(i+1):
            if a[i] == j+1:
                print("YES")
                return
    print("NO")

t = int(input())
for _ in range(t):
    solve()
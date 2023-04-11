t = int(input())
for _ in range(t):
    n = int(input())
    print(2)
    for i in range(1, n+1):
        if i % 2 != 0:
            j = i
            while j <= n:
                print(j, sep=" ", end=" ")
                j *= 2
    print()










def solve():
    n, m = [int(i) for i in input().split()]
    x1, y1, x2, y2 = [int(i) for i in input().split()]
    def nearwall(x, y):
        return x == n or x == 1 or y == 1 or y == m
    def corner(x, y):
        return (x == 1 and y == 1) or (x == 1 and y == m) or (x == n and y == 1) or (x == n and y == m)
    if corner(x1, y1) or corner(x2, y2):
        print(2)
    elif nearwall(x1, y1) or nearwall(x2, y2):
        print(3)
    else:
        print(4)
    


t  =int(input())
for _ in range(t):
    solve()

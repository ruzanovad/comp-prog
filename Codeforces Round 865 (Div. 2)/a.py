
def solve():
    a, b= [int(i) for i in input().split()]
    if a == 1 or b == 1:
        print(1)
        print(a, b)
        return
    print (2)
    print(1, b-1)
    print(a, b)
    




t  =int(input())
for _ in range(t):
    solve()

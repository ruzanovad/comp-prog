
def solve():
    n, x1, y1, x2, y2 = [int(i) for i in input().split()]

    g1 = 0
    g2 = 0
    g3 = 0
    g4 = 0

    if x1 <= n/2:
        g1=x1
    else:
        g1 = n+1 -x1
    if y1 <= n/2:
        g2 =  y1
    else:
        g2=  n+1 -y1

    if x2 <= n/2:
        g3=x2
    else:
       g3= n+1 -x2
    if y2 <= n/2:
        g4 =  y2
    else:
        g4 = n+1 -y2

    getcycle = min(g1, g2)
    getcycle2 = min(g3, g4)
    
    print(abs(getcycle2-getcycle))
    


t  =int(input())
for _ in range(t):
    solve()

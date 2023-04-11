def solve():
    n = int(input())
    if n % 2 == 0:
        print(-1)
        return
    k = (n) // 2
    string = ""
    while k > 0:
        string+=str(k%2+1)
        k//= 2
    print(len(string))
    print(' '.join(string[::-1]))


t = int(input())
for _ in range(t):
    solve()
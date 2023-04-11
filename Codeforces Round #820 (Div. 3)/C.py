from turtle import begin_fill


t = int(input())
for _ in range(t):
    s = input();
    ss = s[1:-1]
    begin = ord(s[0]) - ord('a') + 1
    end = ord(s[-1]) - ord('a') + 1
    for i in range(begin, end):
        while ss.find(i)!=-1:
            

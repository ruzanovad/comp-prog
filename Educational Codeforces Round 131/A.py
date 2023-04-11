t = int(input())
for i in range(t):
    ones = [1 for i in input().split(' ') if i == '1']
    ones.extend([1 for i in input().split(' ') if i == '1'])
    length = len(ones)
    if length == 0:
        print(0)
    elif length == 1 or length == 2 or length == 3:
        print(1)
    else:
        print(2)

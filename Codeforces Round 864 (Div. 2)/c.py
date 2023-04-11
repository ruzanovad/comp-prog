import sys
t = int(input())
for _ in range(t):

    n, m = [int(i) for i in input().split()]
    print("?", 1, 1)
    sys.stdout.flush()
    minim = int(input())
    if (minim == 0):
        print("!", 1, 1)
        sys.stdout.flush()
    else:
        print("?", n, 1)
        sys.stdout.flush()
        minim1 = int(input())
        if minim1 == 0:
            print("!", n, 1)
            sys.stdout.flush()
        else:
            print("?", 1, m)
            sys.stdout.flush()
            minim2 = int(input())
            if minim2 == 0:
                print("!", 1, m)
                sys.stdout.flush()
            else:
                x, y =1, 1
                if minim+ minim1 == n-1:
                    x =  minim+1
                else:
                    
                r = min(minim+1, minim1+1)
                l = 1
                h = max(minim+1, minim1+1)
                while (l < r):
                    mid = l + (r - l)//2
                    if mid < 

    
        if sum != pref[mid] - pref[l-1]:
            r = mid
        else:
            l = mid+1
            

    

 
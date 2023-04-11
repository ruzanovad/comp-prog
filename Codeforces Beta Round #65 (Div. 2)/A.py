from sys import stdin, stdout

def main():
    n = int(stdin.readline())
    for _ in range(n):
        word = (stdin.readline().rstrip())
        if len(word) <= 10:
            stdout.write(word+'\n')
        else:
            stdout.write(word[0]+str(len(word) - 2)+word[-1]+'\n')

if __name__ == '__main__':
    main() 

from math import log10

def find(n):
    if n < 10:
        return 0
    for x in range(10, n):
        a = x
        b = x
        for i in range(int(log10(n))):
            a += x % 10
            x = x // 10
            if a == n:
                return b
    return 0
n = int(input())
print(find(n))
n = int(input())
for i in range(n):
    a = list(input().split())
    for j in range(len(a[1])):
        print(a[1][j]*int(a[0]), end = '')
n, m = map(int,input().split())
arr = [[int(x) for x in input().split()]for y in range(n)]

k = int(input())

for a in range(k):
    i,j,x,y = map(int,input().split())
    sum = 0
    for b in range(i-1,x):
        for c in range(j-1,y):
            sum += arr[b][c]
    print(sum)

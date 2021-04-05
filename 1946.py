def func(n):
    arr = []
    for i in range(n):
        arr.append(list(map(int,input().split())))
    arr.sort()
    arr.reverse()
    print(arr)
    for i in range(n-1):
        if arr[i][0] > arr[i+1][0] and arr[i][1] > arr[i+1][1]:
            return i+1
            break
    return n
        

n = int(input())

for i in range(n):
    print(func(int(input())))
    
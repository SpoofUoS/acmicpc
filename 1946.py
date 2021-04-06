def func(n):
    arr = []
    for i in range(n):
        arr.append(list(map(int,input().split())))
        
    arr.sort(reverse = True)
    print(arr)

    i_1 = arr[0][1]
    
    for i in range(1,n):
        i_1 = arr[0][1]
        if arr[i][1] > i_1:
            a = i
            break
            i_1 = arr[0][1]
    return n-i


n = int(input())

for i in range(n):
    print(func(int(input())))
    
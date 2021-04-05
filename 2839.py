n = int(input())

arr = [1, 2, 4, 7]

arr1 = [3, 5]

arr2 = [6, 8, 10]

arr3 = [9, 11, 13]

arr4 = [12, 14]

def sugar(n):
    if n in arr:
        return -1
    if n in arr1:
        return 1
    if n in arr2:
        return 2
    if n in arr3:
        return 3
    if n in arr4:
        return 4
    if n == 0:
        return 0

if n < 15:
    print(sugar(n))
else:
    a = sugar(n%15)
    add = n // 15
    if a == -1:
        if n%15 == 4 or n%15 == 2:
            print(add*3 + 2)
        elif n%15 == 7:
            print(add*3 + 3)
        else: print(add*3 + 1)
    else:
        print(a+add*3)
        
        
    
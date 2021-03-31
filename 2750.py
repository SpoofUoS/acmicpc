n = int(input())
arr = []
arr2 = []
for i in range(n):
    a = input()
    if a[0] == '-':
        arr.append(a)
    else:
        arr2.append(a)

arr.sort()
arr2.sort()

for i in range(len(arr)):
    print(arr[len(arr)-1-i])

for i in range(len(arr2)):
    print(arr2[i])
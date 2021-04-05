n, l = map(int, input().split())
arr = [int(x) for x in input().split()]

arr.sort()

count = 0

while arr:
    a = arr.pop(0)
    count += 1
    for i in range(len(arr)):
        if arr[0] < a+l: arr.pop(0)
        else: break

print(count)
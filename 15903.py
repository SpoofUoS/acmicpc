n, m = map(int, input().split())

arr = [int(x) for x in input().split()]

arr.sort()

for i in range(m):
    arr[0] = arr[1] = arr[0] + arr[1]
    arr.sort()

a = 0
for i in range(n):
    a += arr[i]

print(a)
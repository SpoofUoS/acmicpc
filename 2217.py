n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))

arr.sort()
arr.reverse()

max_w = arr[0]
for i in range(1,n):
    is_max_w = arr[i]*(i+1)
    if max_w < is_max_w:
        max_w = is_max_w

print(max_w)
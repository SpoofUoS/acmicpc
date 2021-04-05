n = int(input())
arr = [int(x) for x in input().split()]
arr.sort()
arr.reverse()

sum = 0
for i in range(n):
    sum += arr[i]*(i+1)

print(sum)
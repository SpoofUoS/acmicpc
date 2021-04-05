n = int(input())

arr = [int(x) for x in input().split()] 
arr2 = [int(x) for x in input().split()] 

arr.sort()
arr2.sort()

sum = 0

for i in range(n):
    sum += arr[i]*arr2[n-i-1]
    
print(sum)
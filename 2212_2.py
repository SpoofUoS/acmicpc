n = int(input())
k = int(input())

if k>=n:
    print(0)
    exit()

arr = [int(x) for x in input().split()]
arr2 = []       # 수신 감도 차이
arr.sort()

for i in range(1,n):
    arr2.append(arr[i]-arr[i-1])

arr2.sort()

for i in range(k-1):
    arr2.pop()

a = 0
for i in range(len(arr2)):
    a += arr2[i]
    
print(a)
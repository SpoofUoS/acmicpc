city = int(input())

arr = [int(x) for x in input().split()]   # 거리
arr2 = [int(x) for x in input().split()]   # 리터당 가격


price = arr2[0]
sum = 0

for i in range(city-1):
    if price > arr2[i]:
        price = arr2[i]
    sum += arr[i]*price

print(sum)
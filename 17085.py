def cross(arr,i,j,size_of_cross):
    line_len = size_of_cross*2 + 1
    count == 0
    for x in range(line_len):
        if arr[i][size_of_cross] == '#':
            count += 1
        if arr[size_of_cross][i] == '#':
            count += 1
    if count == 2*line_len:
        return 1
    return 0
n,m = map(int,input().split())
arr = []

#for i in range(n):
 #   arr.append(input())

arr = [[str(x) for x in input().split()]for y in range(n)]

print(arr)
print(arr[0][0][0])
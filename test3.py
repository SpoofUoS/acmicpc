def case1(a, i, j): # 세로 
    if a[i][j] == a[i][j+1] == a[i][j+2] == a[i][j+3] == a[i][j+4]:
        if a[i][j] != 0:
            return [i, j]

def case2(a,i,j): # 가로
    if a[i][j] == a[i+1][j] == a[i+2][j] == a[i+3][j] == a[i+4][j]:
        if a[i][j] != 0:
            return [i, j]

def case3(a,i,j): # 대각선
    if a[i][j] == a[i+1][j+1] == a[i+2][j+2] == a[i+3][j+3] == a[i+4][j+4]:
        if a[i][j] != 0:
            return [i, j]
        

list = [[int(x) for x in input().split()]for y in range(19)]
find = []     # 돌이 연속으로 5개가 되는 모든 경우
f_sort = []   # 구하고자 하는 돌의 위치

for i in range(0, 15):
    for j in range(0, 15):
        if case1(list,i,j) != None:
            find.append(case1(list,i,j))
        if case2(list,i,j) != None:
            find.append(case2(list,i,j))
        if case3(list,i,j) != None:
            find.append(case3(list,i,j))

for i in range(0,19):
    if case1(list,i,14) != None:
        f_sort.append(case1(list,i,14))
    if case2(list,14,i) != None:
        f_sort.append(case2(list,14,i))
    if i < 15:
        if case3(list,i,14) != None:
            f_sort.append(case3(list,i,14))
        if case3(list,14,i) != None:
            f_sort.append(case3(list,14,i))
    
for i in range(int(len(find))): # 6목 이상 제외
    if [find[i][0]+1, find[i][1]] not in find and [find[i][0], find[i][1]+1] not in find and [find[i][0]+1, find[i][1]+1] not in find:
        f_sort.append(find[i]) # [2,3]에서 시작한 6목인 경우 [2,4] 또는 [3,3] 또는 [3,4]가 find에 있다.
        break

if f_sort == []: # 결과가 나지 않을 경우
    print(0)
else:            # 누군가가 이길 경우
    print(list[f_sort[0][0]][f_sort[0][1]])
    print(f_sort[0][0]+1, f_sort[0][1]+1)
               

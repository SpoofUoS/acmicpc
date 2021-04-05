n = int(input())
k = int(input())

arr_dic = {}
arr = [int(x) for x in input().split()]
arr.sort()

def find_same_name(a, dic): # a: 리스트
    
    for name in a:                  # 리스트 a에 있는 이름들을 차례로 반복
        if name in dic:       # 이름이 name_dict에 있으면 
            dic[name] += 1    # 등장 횟수를 1 증가
        else:                       # 새 이름이면
            dic[name] = 1     # 등장 횟수를 1로 저장

    
find_same_name(arr, arr_dic)
#print(arr_dic) #  삭제

pointer_count = 0
pointer_arr = [0]

for i in range(1,len(arr)-1):
    
    if (arr[i] - arr[i-1])*arr_dic[arr[i]] > (arr[i+1] - arr[i]) * arr_dic[arr[i+1]]:
        pointer_count += 1
        pointer_arr.append(i)
    if pointer_count == k-1:
        break


pointer_arr.append(len(arr))
print(arr)
print(pointer_arr)

a = len(pointer_arr)-1
sum = 0
for i in range(a):
    for j in range(pointer_arr[i]+1,pointer_arr[i+1]):
        sum += arr_dic[arr[j]]*(arr[j]-arr[pointer_arr[i]])
    
print(sum)

                               
                                  
                                  
                                  
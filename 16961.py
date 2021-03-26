day_dic = {}
day_dic2 = {}
day_dic3 = {}
info = []

for i in range(366):
    day_dic[str(i)] = 0
    day_dic2[str(i)] = 0
    day_dic3[str(i)] = 1

n = int(input())
n5 = 0

for i in range(n):
    x = input().split()
    info.append(x)

for i in range(n):
    if (int(info[i][2])-int(info[i][1])+1)+1 > n5:
        n5 = int(info[i][2])-int(info[i][1]) + 1
for i in range(n):
    if info[i][0] == 'T':
        for j in range(int(info[i][1])-1,int(info[i][2])):
            day_dic[str(j)] += 1
            day_dic2[str(j)] += 1
            day_dic3[str(j)] += 10
    else:
        for j in range(int(info[i][1])-1,int(info[i][2])):
            day_dic[str(j)] += 10000
            day_dic2[str(j)] += 1
            day_dic3[str(j)] -= 10

n1 = 0
n2 = day_dic2['0']
n3 = 0
n4 = 0
for i in range(366):
    if day_dic[str(i)] > 0:
        n1 += 1
    if day_dic2[str(i)] > n2:
        n2 = day_dic2[str(i)]
    if day_dic3[str(i)] == 1:
        if day_dic[str(i)] > 0:
            n3 += 1
        if day_dic2[str(i)] > n4:
            n4 = day_dic2[str(i)]


print(n1)
print(n2)
print(n3)
print(n4)
print(n5)
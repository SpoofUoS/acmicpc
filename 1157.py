def find(a):
    dic = {}
    
    for i in range(len(a)):
        if a[i] in dic:
            dic[a[i]] += 1
        else:
            dic[a[i]] = 1
        
    n = 1
    result = []
    
    for letter in dic:
        if dic[letter] >= n:
            n = dic[letter]
    
    for letter in dic:
        if dic[letter] == n:
            result.append(letter)
        
    
    if len(result) >= 2: return '?'
    else: return result[0]
    
a=input().upper()

print(find(a))
num=[1,6,5,8,9]
target=7
result=[]

for i in range(0,len(num)):
    for j in range(i+1,len(num)):
        if num[i]+num[j]==target:
            result.extend([i,j])
            break   #break after finding out, why keep searching since only 1 ans req
print(result)

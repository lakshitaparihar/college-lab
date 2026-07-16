arr=[1,0,1,1,1,0,0,1,0,1,1,1,1]
# arr=[1,0,0,1,1,0,1,1,1,0,1]
streak=0
best=0
for i in arr:
    if i==1:
        streak+=1
        if streak>best:
            best=streak
    elif i==0:
        streak=0
print(best)
    

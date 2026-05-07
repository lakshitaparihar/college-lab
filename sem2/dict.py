number=int(input("enter number of elements in your alphabetical list: "))
l=[]
for i in range(1,number+1):
    element=input(f"enter element no.{i}: ").title()
    l.append(element)

l.sort()
print(l)
dict={}
for i in l:
    value=i
    key=l.index(i)
    dict[key]=value

print(dict)
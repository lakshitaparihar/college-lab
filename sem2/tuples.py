t=(1,3,5,7,9,4,2,10)
print(t)
print(t[0])
print(t[-1])
print(t[::])
print(t[::-1])
print(t[3::])
print(t[:3:])
print(t[-3:])
print(f"max value: {max(t)}")
print(f"min value: {min(t)}")
print(f"length: {len(t)}")

for i in t:
    print(i)
l=[]
number=int(input("enter number of elements in your integer tuple: "))
for i in range(1,number+1):
    element=int(input(f"enter element no.{i}: "))
    l.append(element)

tpl=tuple(l)
print(tpl)
print(tpl+t)





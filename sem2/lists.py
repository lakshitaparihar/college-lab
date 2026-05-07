number=int(input("enter number of elements in your integer list: "))
list=[]
for i in range(1,number+1):
    element=int(input(f"enter element no.{i}: "))
    list.append(element)
print(list)
list.sort()
print(list)
list.sort(reverse=True)
print(list)
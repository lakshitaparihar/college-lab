n1=int(input("enter the first number: "))
n2=int(input("enter the second number: "))
n3=int(input("enter the third number: "))
largest=n1
if n2>largest:
    largest=n2
if n3>largest:
    largest=n3
print("largest number out of these is",largest)
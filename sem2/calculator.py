def add(n1,n2):
    sum=n1+n2
    print("sum of the entered integers is",sum)

def sub(n1,n2):
    subs=n1-n2
    print(f"{n2} substracted from {n1} gives",subs)

def div(n1,n2):
    divide=n1/n2
    print(f"{n1} divided by {n2} is",divide)

def multi(n1,n2):
    prod=n1*n2
    print("product of entered numbers is",prod)

def mod(n1,n2):
    modulus=n1%n2
    print(f"{modulus} is left when {n1} is divided by {n2}")

operation=input("enter operation to be performed, out of (addition,substraction,division,product,modulus): ")
num1=int(input("enter the first number: "))
num2=int(input("enter the second number: "))
if operation=="additon":
    add(num1,num2)
elif operation=="substration":
    sub(num1,num2)
elif operation=="division":
    div(num1,num2)
elif operation=="product":
    multi(num1,num2)
elif operation=="modulus":
    mod(num1,num2)
else:
    print("either incorrect or invalid input entered")
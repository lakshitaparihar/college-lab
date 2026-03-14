n1=int(input("enter the first number: "))
n2=int(input("enter the second number: "))
# temp=n1 #using a temporary variable
# n1=n2
# n2=temp
n1,n2=n2,n1 #without using a temporary variable
# n1=n2
# n2=n1 #this makes ni and n2 the same value, second number
print(f"after swapping\nfirst number: {n1}\nsecond number: {n2}")

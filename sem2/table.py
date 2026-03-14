num=int(input("enter the number whose table is to  be generated: "))
# i=1
# while i<=10:
#     print(f"{num} times {i} is",num*i)
#     i+=1

l=[r"zero's",r"one's",r"two's",r"three's",r"four's",r"five's",r"six's",r"seven's",r"eight's",r"nine's",r"ten's"]
i=0
while i<=10:
    t=i*num
    print(f"{num} {l[i]} are {t}.")
    i+=1


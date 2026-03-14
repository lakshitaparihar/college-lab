literal=input("enter the word to know its data type: ")
if literal=="None":
    print("data type: NONE")
elif literal=="True" or literal=="False":
    print("data type: BOOLEAN")
elif literal[-1]=="j":
    if (literal.count("+")==1 or literal.count("-")==1):
        digit=""
        for i in literal:
            if i=="+" or i=="-" or i=="j":
                i=""
                digit+=i
            else:
                digit+=i
        if digit.isdigit()==True:
            print("data type: COMPLEX NUMBER")
    elif literal[:-1].isdigit()==True:
        print("data type: COMPLEX NUMBER")
elif (literal[0].isdigit()==True or literal[0]=="+" or literal[0]=="-") and literal[1:].isdigit()==True:
    print("data type: INTEGER")
elif literal.count(".")==1 and (literal[0]=="-" or literal[0]=="+" or literal[0].isdigit()==True):
    digits=""
    for i in literal:
        if i==".":
            i=""
            digits+=i
        else:
            digits+=i
            
    if digits[1:].isdigit()==True:
        print("data type: FLOATING POINT NUMBER")
elif literal=="0":
    print("data type: INTEGER")
else:
    print("data type: STRING")


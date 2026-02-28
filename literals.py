# literal=input("enter a literal: ")
# print("entered literal is of data type",type(literal))
# if int(literal)==int:
#     print("integer entered")
# elif literal=="True" or literal=="False":
#     print("boolean entered")
# elif literal==str:
#     print("string entered")
# else:
#     print("complex entered")



#Incorrect type comparison
# I wrote int(literal) == int to check whether the input was an integer.
# This is wrong because int(literal) converts the value into a number, while int is the data type itself. Comparing a value with a type will always be false. Also, if the input is not numeric, int(literal) causes a crash.

# Comparing input with str directly
# I used literal == str to check for a string.
# This is incorrect because str is the Python string class, not the user’s input value. A text like "hello" will never be equal to the object str.

# Forgetting that input() always returns a string
# I assumed Python automatically detects the type of user input.
# Actually, input() always returns text. Even if the user types 5, Python stores "5". Therefore, type checking must be done by converting or analysing the string.


# x ="10"
# print(type(x))

# #program to check class of a input literal alternate method
# literal = input("enter a literal: ")

# if literal == "True" or literal == "False":
#     print("boolean entered")

# else:
#     try:
#         int(literal)
#         print("integer entered")
#     except:
#         try:
#             complex(literal)
#             print("complex entered")
#         except:
#             print("string entered")



literal = input("enter a literal: ")
if literal == "True" or literal == "False":
    print("boolean entered")
elif literal.count(".") == 1 and literal.replace(".", "").replace("-", "", 1).isdigit():
    print("float entered")
elif literal.isdigit() or (literal[0] == "-" and literal[1:].isdigit()):
    print("integer entered")
elif literal.count("j") == 1 and literal[-1] == "j":
    print("complex entered")
else:
    print("string entered")


# Weak complex-number detection logic, I checked only whether the letter j exists in the input. This incorrectly marked invalid values like 12j6 or 34j+4 as complex numbers. A proper complex literal must follow Python’s numeric format.


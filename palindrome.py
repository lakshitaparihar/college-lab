word=input("enter the word to check: ")
if word==word[::-1]:
    print("entered word is a palindrome.")
else:
    print("entered word is not a palindrome")
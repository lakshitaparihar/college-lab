#print("potential_identifier".isidentifier())
print("PROGRAM TO CHECK IF A WORD IS A VALID IDENTIFIER OR NOT")
word=input("enter the word you want to check:")
valid=True
if word[0].isdigit():
    valid=False  
for i in range(len(word)):
    if not word[i]=="_" and not word[i].isalnum():
        valid=False
        break
if valid==True: 
    print("valid identifier")
else:
    print("invalid identifier")
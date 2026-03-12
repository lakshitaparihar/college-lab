# a=input()
# print(a)
def checkword(word):
    if word == "":
        return "empty input. please enter a word."
    keywords = [
        "False", "None", "True",
        "and", "as", "assert", "async", "await",
        "break",
        "class", "continue",
        "def", "del",
        "elif", "else", "except",
        "finally", "for", "from",
        "global",
        "if", "import", "in", "is",
        "lambda",
        "nonlocal", "not",
        "or",
        "pass",
        "raise", "return",
        "try",
        "while", "with",
        "yield",
        "match", "case"
    ]
    a=True
    for i in keywords:
        if i==word:
            a=False
            return "entered word cannot be an indentifier, as it is a keyword."
    if (word[0]=="_" or word[0].isalpha()) and a==True:
            w=''
            for i in word:
                if i=="_":
                    i=""
                    w+=i
                else:
                    w+=i
            if w.isalnum():
                return "this word is an valid identifier, as well as a valid variable since all variables are a valid identifiers."
            else:
                return "this is an invalid identifier."
    else:
         return "this is an invalid identifier."
    
    

carryon=True
while carryon:
    word=input("enter a word: ")
    print(checkword(word))
    go_on=input("wanna continue? (Y/N) ").upper()
    if go_on=='N':
        carryon=False
    elif not go_on=='Y':
        print("invalid input")
        







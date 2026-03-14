def wordcount(text):
    # count=1           #a sentence has no of spaces+1 words, ex: hi there, has 2 words but one space
    # for i in text:
    #     if i==" ":
    #         count+=1
    # return count
    l=text.split()   #cleaner func
    word_count=len(l)
    return word_count


def toggletext(text):
    new_text=""
    for i in text:
        if i.upper()==True:
            i=i.lower()
            new_text+=i
        elif i.lower()==True:
            i=i.upper()
            new_text+=i
        else:
            new_text+=i
    return new_text

def replace(text,word_to_replace,word_to_be_replaced):
    text2=[]
    for i in text:
        text2.append(i)
    word=[]
    for i in word_to_replace:
        word.append(i)
    replaceword=[]
    for i in word_to_be_replaced:
        replaceword.append(i)
    for i in word:
        for j in text2:
            if j in replaceword:
                text2.remove(j)
                text2.append(i)
    new_text=''
    for i in text2:
        new_text+=i
    return new_text



text=input("enter text: ")
operation=input("enter the desired operation: ").lower()
if operation=="count words":
    print("no. of words in the entered text:",wordcount(text))
elif operation=="toggle text":
    # print(text.swapcase())
    print(toggletext(text))
elif operation=="replace word":
    word_to_replace=input("enter the word to replace with: ")
    word_to_be_replaced=input("enter the word to be replaced: ")
    # print(text.replace(word_to_be_replaced,word_to_replace))
    print(replace(text,word_to_replace,word_to_be_replaced))
else:   
    print("invalid input")

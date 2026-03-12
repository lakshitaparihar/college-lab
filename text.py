def wordcount(text):
    count=1 #a sentence has no of spaces+1 words, ex: hi there, has 2 words but one space
    for i in text:
        if i==" ":
            count+=1
    return count




text=input("enter text: ")
operation=input("enter the desired operation: ").lower()
if operation=="count words":
    print("no. of words in the entered text:",wordcount(text))
elif operation=="toggle text":
    print(text.swapcase())
elif operation=="replace word":
    word_to_replace=input("enter the word to replace with: ")
    word_to_be_replaced=input("enter the word to be replaced: ")
    print(text.replace(word_to_be_replaced,word_to_replace))
else:   
    print("invalid input")

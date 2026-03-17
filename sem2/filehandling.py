def replace(list,replace,replacewith):
        matter=''
        for i in list:
             matter+=(" "+ i)
        matter=matter.replace(replace,replacewith)
        print(matter)
        print("\n")


with open('mytext.txt','r+', errors='replace') as story:
    story.seek(0)
    text=story.read()
    print("ORIGINAL CONTENT:\n",text)
    words=text.split()
    # print(text.split())
    # print(text.split("\n"))
    # print(text.split('road'))
    print("WORD COUNT:",len(words))
    print("\n")
    replaceword=input("enter the word to replace: ")
    replacedwith=input("enter the word to replace that word with: ")
    replace(words,replaceword,replacedwith)
    for i in words:
        if i.upper()==i:
            i=i.lower()
            story.write(i+' ')
        elif i.lower()==i:
            i=i.upper()
            story.write(i+' ')
        else:
            story.write(i+' ')
    story.truncate()
    story.seek(0)
    print("TOGGLED CONTENT:\n",story.read())
    story.seek(0)
    text=story.read()
    words=text.split()
    print("WORD COUNT:",len(words))
#python demo library
books_available=[
    "The Silent Patient",
    "Atomic Habits",
    "The Alchemist",
    "1984",
    "To Kill a Mockingbird",
    "Think and Grow Rich",
    "Fahrenheit 451",
    "Slaughterhouse-Five",
    "Catch-22",
    "The Bell Jar",
    "Jane Eyre",
    "Wuthering Heights",
    "Little Women",
    "Moby Dick",
    "The Odyssey",
    "The Iliad",
    "Don Quixote",
    "Dracula",
    "Frankenstein"
]

issued_books=[
    "It",
    "Pet Sematary",
    "The Stand",
    "The Road Less Traveled"
]

def library():
    print("available books:")
    for i in books_available:
        print(i)
    print("issued books:")
    for i in issued_books:
        print(i)
    
def search(book):
    if book in books_available:
        print("here's your required book.")
        return "available"
    elif book in issued_books:
        print("book currently not available.")
        return "issued"
    else:
        print("book not in our python demo library")
        return "not available"

def issue_book(book):
    if search(book)=="available":
        issued_books.append(book)
        books_available.remove(book)
        print("book issuedto you.")
    elif search(book)=="not available":
        print("book not available in our library at all.")
    elif search(book)=="issued":
        print("book currently issued to someone else.")

def return_book(book):
    if book in issued_books:
        issued_books.remove(book)
        books_available.append(book)
        print("book returned")
        
start=True
library()
while start:
    opp=input("you can search the book, get it issued, return it or leave" \
    " using search, issue, return and exit respectively." \
    "\nenter desired opperation: ").lower().strip()
    if opp=="library":
        library()
    elif opp=="fine":
        pass
    elif opp=="exit":
        break
    else:
        book=input("enter desired book: ").strip()
        if opp=="issue":
            issue_book(book)
        elif opp=="return":
            return_book(book)
        elif opp=="search":
            search(book)
        else:
            break


#mistakes:
#In Python, or "exit" doesn't mean "or if the variable equals exit." 
# It means "or if the string 'exit' exists." Since "exit" is a non-empty string, Python always sees it as True. 
# So, no matter what you type (search, issue, return), that line evaluates to True and hits the break command.
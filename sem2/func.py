def calculate_area(length, width=5):  # width is a default argument
    return length * width


print("1. Calculate Area (Positional: Length=10, Width=20)")
print("2. Calculate Area (Default: Length=10, uses default Width=5)")
print("3. Calculate Area (Keyword: Width=15, Length=5)")
print("4. Exit")
while True:
    choice = input("Enter choice (1-4): ")
    
    if choice == '1':
        print("Area:", calculate_area(10, 20)) # Positional
    elif choice == '2':
        print("Area:", calculate_area(10))     # Using Default Width
    elif choice == '3':
        print("Area:", calculate_area(width=15, length=5)) # Keyword
    elif choice == '4':
        break
    else:
        print("Invalid choice!")



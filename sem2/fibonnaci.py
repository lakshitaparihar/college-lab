n = int(input("How many numbers do you want? "))
a = 0
b = 1
print("Fibonacci Series:")
for i in range(n):
    print(a, end=" ")  # 1. Print the current number
    
    c = a + b          # 2. Calculate the next one
    a = b              # 3. Move 'b' to 'a' (Shift left)
    b = c              # 4. Move 'c' to 'b' (Shift left)
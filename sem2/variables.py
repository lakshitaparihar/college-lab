#global variable
message = "I am global"

def scope_demo():
    # Local variable
    message = "I am local"
    print("Inside function (local):", message)

scope_demo()
print("Outside function (global):", message)


#modify global
counter = 10

def modify_global():
    global counter  # Using the 'global' keyword to modify
    counter = counter + 5
    print("Value inside function after modification:", counter)

modify_global()
print("Value outside function after modification:", counter)
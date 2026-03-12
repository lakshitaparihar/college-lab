char=input("enter a character: ").lower()
vowels=["u","o","i","e","a"]
if char in vowels:
    print("entered character is a vowel")
elif char.isalpha():
    print("entered character is a consonant")
else:
    print("enter only alphabets")
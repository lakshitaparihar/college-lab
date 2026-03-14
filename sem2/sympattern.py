string="#"
pattern='@'
for i in range(5):
    t=ord(pattern)+ord(string)
    print(chr(t)*i)
    
print(ord('c'))
print(ord('@'))
print(ord('#'))

# print(ord('B'))
# print(chr(66))

string="#"
pattern='_'
for i in range(5):
    t=ord(pattern)+ord(string)
    print(chr(t)*i)
    
print(ord('_'))
print(ord('#'))   # sum of ord of _ and # is 130 which exceeds the limit of ascii codes(0-127), hence nothing prints.
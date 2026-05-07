words = [
    "apple", "banana", "orange", "apple",
    "grape", "banana", "apple", "kiwi",
    "orange", "grape", "banana", "mango",
    "apple", "kiwi", "banana"
]
print(words)
freq = {}
for word in words:
    if word in freq:
        freq[word] += 1
    else:
        freq[word] = 1
print(freq)
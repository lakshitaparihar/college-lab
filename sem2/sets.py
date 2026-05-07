s1={i*3 for i in range(10)}
print(s1)
s2={i*6 for i in range(10)}
print(s2)
# print(s1.issubset(s2))
# print(s2.issubset(s1))
print(f"difference: {s1-s2}")
print(f"union: {s1|s2}")
print(f"intersection: {s1&s2}")
print(f"in either: {s1^s2}")
# print(s1.issubset(s1))
# print(s2>s1) #proper subset: has all and more other elements

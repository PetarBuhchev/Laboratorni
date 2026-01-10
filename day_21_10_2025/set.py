s1 = {1,5,3,7}
print(s1)
s2 = set([1,2,3,3,2,1])
print(s2)

## len (<set>)
s1.add(4)
print(s1)

s1.remove(3)
print(s1)

s1.discard(5)
print(s1)

s1 = {1,2,3,4,5}
s2 = {3,5,6,9}
print(s1 | s2)
print(s1 - s2)
print(s1 & s2)
print(s1^s2)

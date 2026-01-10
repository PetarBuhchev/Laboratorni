##Задача 1
## Въвеждат се 3 числа, намираме най малкото от тях и принтираме
n1 = int(input('n1: '))
n2 = int(input('n2: '))
n3 = int(input('n3: '))
min = 0
if n1 > n2:
    if n2 > n3:
        min = n3
    else:
        min = n2
elif n2 > n1:
    if n1 > n3:
        min = n3
    else:
        min = n1
elif n3 > n2:
    if n2>n1:
        min = n1
    else:
        min = n2

if n1 == n2 and n2 == n3:
    min = n1
print(min)
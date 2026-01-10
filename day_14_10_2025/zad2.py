## Въвеждат се n (по голямо от 5 и по малко от 20) брой числа, намира се най малкото число
n = int(input("Въведете броят на числата: "))
while n <= 5 or n >= 20:
    n = int(input("Въведете правилен брой числа: "))

minimum_value = 0
for x in range(n):
    number = int(input())
    if x == 0:
        minimum_value = number
    else:
        if number < minimum_value:
            minimum_value = number

print(minimum_value)


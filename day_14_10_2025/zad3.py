##Да се намери сумата на числата от зад.2 на които цифрата на десетиците е четно число
n = int(input("Въведете броят на числата: "))
while n <= 5 or n >= 20:
    n = int(input("Въведете правилен брой числа: "))

minimum_value = 0
sum_value = 0
for x in range(n):
    number = int(input())
    if x == 0:
        minimum_value = number
    else:
        if number < minimum_value:
            minimum_value = number

    if number // 10 != 0:
        if ((number//10)%10) % 2 == 0:
            sum_value += number


print(minimum_value)
print(sum_value)


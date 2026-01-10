## Програма, в която е описана функция, която проверява дали едно
## цяло число е просто, числото се предава като аргумент на функ.
## Фунцкията, връща като резултат True или False
## Да се принтират всички прости числа от 2 до това число (main())
def prime_number(number):
    is_prime = True
    if number >= 2:
        for i in range(2, number):
            if number % i == 0:
                is_prime = False
                break
    else:
        print("Input correct number")
        return
    return is_prime
number = int(input())
print(prime_number(number))
if number > 2:
    for i in range(2, number+1):
        is_prime = True
        for j in range(2, i):
            if i % j == 0:
                is_prime = False
                break
        if is_prime:
            print(i)
elif number == 2:
    print(2)
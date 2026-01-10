#Задача 1
from datetime import date

print("Здравей Python")
#Задача 2
print("  **   **  ")
print(" *  * *  * ")
print("*    *    *")
print("*         *")
print(" *       * ")
print("  *     *  ")
print("   *   *   ")
print("    * *    ")
print("     *     ")
print("******************************")
#Задача 3
#name = input("Въведи името си: ")
#year_of_birth = int(input("Въведете Вашата година на раждане: "))
#current_year = date.today().year
#current_year1 = int(input("Въведете текущата година: "))

#print(f"Здравей, аз съм {name} и съм на {current_year1-year_of_birth}.")
#print(f"Здравей, аз съм {name} и съм на {current_year-year_of_birth}.")
#Задача 4
#height = float(input("Въведете височината на трапеца: "))
#width = float(input("Въведете широчината на трапеца: "))
#length = float(input("Въведете дължината на трапеца: "))

#print(f"Трапецът е с височина {height}см, широчина {width}см и дължина {length}см.")
#print(f"Трапецът има лице: {(((length+width)*height)/2):.3f}см2")
#Задача 5
#count_hours = int(input("Въведете броя на отработените часове: "))
#money_per_hour = float(input("Въведете парите на час: "))
#print(f"Брутното възнаграждение е: {(count_hours*money_per_hour):.2f}.")
#Задача 6
number = input()
num1 = int(number)
# Сума на цифрите, и размяна на първата и последната цифра на
sum = int(number[0]) + int(number[1]) + int(number[2]) + int(number[3])
print(sum)
new_number = number[3] + number[1] + number[2] + number[0]
print(new_number)

poslednaTsifra = num1%10
print(poslednaTsifra)
tretaTsifra = (num1//10)%10
vtoraTsifra = (num1//100)%10
print(tretaTsifra)
print(vtoraTsifra)
parvaTsifra = (num1//1000)%10
print(parvaTsifra)
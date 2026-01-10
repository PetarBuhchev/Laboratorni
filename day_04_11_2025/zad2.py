## Функция която приема 2 аргумента, списък с цели числа и цяло число. Променете всички елементи
## от списъка, чиято стойност е по голяма от подадената като аргумент число на 0
def change_The_List(l1,n):
    for i in range(len(l1)):
        if l1[i] > n:
            l1[i] = 0
    return l1

a = int(input())
b = int(input())
c = int(input())
l1 = [a,b,c]
n = int(input())
l1 = change_The_List(l1,n)
print(l1)

number = int(input())
l = []
for i in range(number):
    a = int(input())
    l.append(a)
def sabirane(a,b):
    return a+b
def izvazhdane(a,b):
    return a-b
def delene(a,b):
    return a/b
def umnozhenie(a,b):
    return a*b

inputed = input()
inputed = inputed.lower()
if inputed == "събиране":
    a = float(input())
    b = float(input())
    print(sabirane(a,b))
elif inputed == "изваждане":
    a = float(input())
    b = float(input())
    print(izvazhdane(a,b))
elif inputed == "делене":
    a = float(input())
    b = float(input())
    if b > 0:
        print(delene(a,b))
    else:
        print("Не може b ДА Е 0")
elif inputed == "умножение":
    a = float(input())
    b = float(input())
    print(umnozhenie(a,b))
else:
    print("Не съществува такъв метод :(")

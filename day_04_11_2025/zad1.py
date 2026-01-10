## програма, която намира лице на гео. фигура. Въвежда се вида на фигурата (квадрат, триъгълник,
## правоъгълник или правоъгълен триъгълник). За всяка фиг. направете отделна функция
def area_Square(a):
    return a*a
def area_Rectangle(a,b):
    return a*b
def area_Triangle(a,h):
    return (a*h)/2
def area_Triangle90(a,b):
    return (a*b)/2
shape = input("Въведи квадрат, правоъгълник, триъгълник или правоъгълен триъгълник: ")
shape = shape.lower()
if (shape == "квадрат"):
    a = float(input("Въведете страната на квадрата: "))
    if (a > 0):
        print(area_Square(a))
    else:
        print("Въведете правилна стойност за страната.")
elif (shape == "правоъгълник"):
    a = float(input("Въведете дължината на правоъгълника: "))
    b = float(input("Въведете широчината на правоъгълника: "))
    if a > 0 and b > 0:
        print(area_Rectangle(a,b))
    else:
        print("Въведете правилна стойност за страната.")
elif (shape == "триъгълник"):
    a = float(input("Въведете страната на триъгълника: "))
    h = float(input("Въведете височината на триъгълника: "))
    if a > 0 and h > 0:
        print(area_Triangle(a,h))
    else:
        print("Въведете правилна стойност за страната.")
elif (shape == "правоъгълен триъгълник"):
    a = float(input("Въведете катет №1 на триъгълника: "))
    b = float(input("Въведете катет №2 на триъгълника: "))
    if a > 0 and b > 0:
        print(area_Triangle(a,b))
    else:
        print("Въведете правилна стойност за страната.")
else:
    print("Не съществува такава фигура в програмта")
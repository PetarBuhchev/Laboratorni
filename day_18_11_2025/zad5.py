import sys

class Product():
    def __init__(self, id, name, price, quantity):
        self.id = id
        self.name = name
        self.price = price
        self.quantity = quantity
    def Print_info(self):
        print(self.id, self.name, self.price, self.quantity)
    def Sale(self, quantity):
        if self.quantity >= quantity:
            self.quantity -= quantity
        else:
            print("You cant sell that much of the product")
    def Purchase(self, quantity):
        self.quantity += quantity
def Search_by_ID(id):
    for prod in list_of_products:
        if prod.id == id:
            return prod
def Search_by_Name(name):
    for prod in list_of_products:
        if prod.name == name:
            return prod
def Exit():
    sys.exit()

product1 = Product(1,'Lukanka',20, 540)
product2 = Product(2,'Kufte',10, 270)
list_of_products = [product1, product2]
product1.Sale(10)
product2.Sale(20)
product1.Purchase(30)
product2.Purchase(40)
product1.Print_info()
product2.Print_info()
print(Search_by_ID(1))
print(Search_by_Name('Lukanka'))
Exit()
product1.Print_info()
class Animal:
    def __init__(self, name, age):
        self.name = name
        self.__age = age
    def get_age(self):
        return self.__age
    def set_age(self, age):
        self.__age = age
class Dog(Animal):
    pass
dog1 = Dog('Sharo', 3)
animal = Animal('Sharo', 3)
print(animal.set_age(10))
print(animal.get_age())



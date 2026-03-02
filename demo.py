class Car():
    def __init__(self, car_brand, car_model, car_price, car_color, manifacture_year):
        self.car_brand = car_brand
        self.car_model = car_model
        self.car_price = car_price
        self.car_color = car_color
        self.manifacture_year = manifacture_year
    def display_info(self):
        print(self.car_brand, self.car_model, self.car_price, self.car_color, int(self.manifacture_year))

def sort_price(cars):
    cars.sort(key=lambda car: car.price)
    return cars
def list_by_brand(cars, brand_name):
    for car in cars:
        if car.brand == brand_name:
            print(car.display_info())
def search_color(cars, color_name):
    index_of_the_most_expensive_car = 0
    price = 0
    for car in range(len(cars)):
       if cars[car].color == color_name:
           if price < cars[car].price:
               index_of_the_most_expensive_car = car
               price = cars[car].price
    print(cars[index_of_the_most_expensive_car].display_info())
def newest_car(cars):
    for car in cars:
        if car.manifacture_year == 2022:
            print(car.display_info())

cars = []
n = int(input('How many cars do you have?'))
for i in range(n):
    brand = input('Brand:')
    model = input('Model:')
    price = float(input('Price:'))
    color = input('Color:')
    manifacture_year = int(input('Manifacture Year:'))
    cars.append(Car(brand, model, price, color, manifacture_year))

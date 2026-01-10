try:
    name = input("Enter your name: ")
    for symbol in name.lower():
        if ord(symbol) not in range(ord("a"), ord("z")):
            raise ValueError("The name should not contain special characters and numbers")
    if len(name) < 2:
        raise ValueError("Name must be at least 2 characters long")
    age = input("Enter your age: ")
    for symbol in age:
        if ord(symbol) not in range(ord("0"), ord("9")+1):
            raise ValueError("The age should not contain special characters and letters")
    age = int(age)
    if age < 0 or age > 150:
        raise ValueError("Age must be between 0 and 150")
except ValueError as ve:
    print("Incorrect input")
    print(ve)
else:
    print("Successfully entered your input")
    if age >= 18:
        print("You can vote")
    else:
        print("You cannot vote")
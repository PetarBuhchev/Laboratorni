input_string = input().split(" ")
n = int(input())

try:
    for i in range(len(input_string)):
        input_string[i] = int(input_string[i])
    while n > 0:
        input_string.remove(min(input_string))
        n -= 1
except ValueError: print("The list is smaller than you expected :)")
except IndexError: print("The list is smaller than you expected :)")
else:
    print(input_string)
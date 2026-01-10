##  Напишете програма, дефинирана функция, която връща като резултат
##второто по-големина число от списък предаден като аргумент на
## функцията.
def second_biggest_in_list(l1):
    count = 0
    s1 = set(l1)
    if len(s1) > 1:
        for x in s1:
            count += 1
            if count == len(s1)-1:
                return x
    else:
        for x in s1:
            return x
l = [3,7,1,8,9]
print(second_biggest_in_list(l))
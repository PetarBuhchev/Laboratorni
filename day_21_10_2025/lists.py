## Lists
lst1 = [1,3,5,7]
lst1[1] = 30

lst2 = list('Python')
print(lst2)

lst3 = []
lst3.append(30)
lst3.append(10)

##List comprehension
## <израз> for <променлива> in <диапазон> if <условие>
lst4 = [x for x in range(1,21) if x%3 != 0]

## Извличане на сечение
## lst5 = lst4[<начало> : <край> : <стъпка>]
lst5 = [1,2,3,4,5,6,7]
print(lst5[::-1])
print(lst5[1:])
print(lst5[:-1])
print(lst5[-1:])

lst = [1,2,4,8,10]
for x in lst:
    print(x)

for ind in range(len(lst)):
    lst[ind] = lst[ind] *10
    print(lst[ind])

print(lst.index(20))
print(lst.count(2))

lst.append(30)
lst.insert(2,25)
lst.remove(20)
print(lst)
lst.pop()
print(lst)
del lst[1]

print(lst)
lst.reverse()
print(lst)
lst.sort()
print(lst)
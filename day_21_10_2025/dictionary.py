## d1 = {"name" : 'value'}

d2 = dict({'ivan':'petrov'})
print(d2)

d3 = dict([('name','ivan'),('lastname','Petrov')])
print(d3)

d4 = {}
d4['name'] = 'ivan'
d4['lastname'] = 'Petrov'
print(d4)
d4['age'] = 20
print(d4)
d4['name'] = 'Petko'
print(d4)
## len, in

for key in d4.keys():
    print(key, d4[key])

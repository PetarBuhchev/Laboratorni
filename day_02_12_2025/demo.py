##За да се отвори файл се използва 'open()'.
##Очакват се два аргумента('име на файл', режим на достъп до файла
f = open('New Text Document.txt', 'a+')
fruits = 'Apple \norange'
f.write(fruits)
print(f.tell())
f.seek(0)
print(f.read())


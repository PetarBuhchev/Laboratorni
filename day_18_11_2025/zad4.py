class Objects():
    def __init__(self, l):
        l1 = []
        for i in l:
            if str(i).isnumeric():
                l1.append(i)
        self.l1 = l1
    def __str__(self):
        return str(self.l1)
    def avrg(self):
        return sum(self.l1) / len(self.l1)


l = [1, 'a', 6, 'c', 12, 'ds', 15]
obj1 = Objects(l)
print(obj1)
print(obj1.avrg())
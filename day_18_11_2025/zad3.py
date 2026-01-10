class Objects:
    def __init__(self, l1):
        self.l1 = l1
def sum_obj(obj1, obj2):
    length1 = len(obj1)
    length2 = len(obj2)
    l = []
    if length1 > length2:
        for i in range(length2):
            l.append(obj1[i]+obj2[i])
        for i in range(length2, length1):
            l.append(0)
    elif length2 > length1:
        for i in range(length1):
            l.append(obj1[i]+obj2[i])
        for i in range(length1, length2):
            l.append(0)
    obj3 = Objects(l)
    return obj3

obj1 = Objects([3,7,1,8,9])
obj2 = Objects([4,9,12,3])
print(sum_obj(obj1.l1, obj2.l1))
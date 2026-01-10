with open('File_for_zad1.txt', 'w') as f:
    s1 = 'String1\n'
    s2 = 'String2\n'
    s3 = 'String3\n'
    l1 = ['List1' , 1]
    l2 = ['List1' , 2]
    f.writelines(s1)
    f.writelines(s2)
    f.writelines(s3)
    for l in l1:
        f.write(f'{str(l)}\n')
    for l in l2:
        f.write(f'{str(l)}\n')
with open('File_for_zad1.txt', 'r') as f:
    print(f.read())
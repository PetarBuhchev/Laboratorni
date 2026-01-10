with open('File_for_zad2.txt', 'r') as f:
    for line in f:
        for word in line.split(" "):
            glasni = ['a', 'e', 'i', 'o', 'u']
            lower_word = word.lower()
            if lower_word[0] in glasni:
                with open('File_for_zad2_1.txt', 'a') as w:
                    w.write(f'{word}\n')

with open('File_for_zad2_1.txt', 'r') as f:
    print(f.read())
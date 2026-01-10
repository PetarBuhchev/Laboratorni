input_string = input().split(",")
mnozhitel = int(input_string[0])
broi = int(input_string[1])
l = []
l.append(mnozhitel)
for i in range(1,broi):
    l.append((l[i-1])+mnozhitel)
print(l)
pswd = input("Enter the password: ")
crypted = ""
for i in range(len(pswd)):
    asc_inp = ord(pswd[i])
    asc_out = asc_inp+3
    crypted += chr(asc_out)
print(crypted)
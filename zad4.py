def check(word):
    new_word = ""
    for i in range(len(input_word)-1,-1,-1):
        new_word += input_word[i]
    if new_word == input_word:
        return "YES"
    else:
        return "NO"

input_word = input()
print(check(input_word))

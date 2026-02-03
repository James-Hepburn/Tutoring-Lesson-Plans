word = input()

new_word = ""
alphabet = "abcdefghijklmnopqrstuvwxyz"
closest_vowel = "aaaeeeeiiiiioooooouuuuuuuu"
next_consonant = "bcdffghjjklmnppqrstvvwxyzz"

for i in word:
  new_word += i
  if i not in "aeiou":
    index = alphabet.index (i)
    new_word += closest_vowel[index]
    new_word += next_consonant[index]
    
print (new_word)
    

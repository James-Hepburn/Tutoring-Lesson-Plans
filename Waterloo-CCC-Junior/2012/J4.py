k = int (input())
word = input()

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
new_word = ""

for i in range (len (word)):
  s = 3 * (i + 1) + k
  index = alphabet.index (word[i])
  new_word += alphabet[index - s]
  
print (new_word)

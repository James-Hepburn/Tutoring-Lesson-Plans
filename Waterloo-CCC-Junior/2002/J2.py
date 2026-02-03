consonants = "bcdfghjklmnpqrstvwxz"

while True:
  word = input()
  if word == "quit!":
    break
  if len (word) >= 4 and word[-2:] == "or" and word[-3] in consonants:
    print (word[:-2] + "our")
  else:
    print (word)
    

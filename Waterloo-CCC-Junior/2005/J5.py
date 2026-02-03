def monkey_word (word):
  while "ANA" in word or "BAS" in word:
    while "ANA" in word:
      word = word.replace ("ANA", "A")
    while "BAS" in word:
      word = word.replace ("BAS", "A")
  return word == "A"

while True:
  word = input()
  
  if word == "X":
    break

  if monkey_word (word):
    print ("YES")
  else:
    print ("NO")

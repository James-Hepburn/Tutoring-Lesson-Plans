import random

pin = str (random.randint (1000, 9999))

a = "_"
b = "_"
c = "_"
d = "_"

for i in range (5):
  print ()
  print (i+1, "- Guess the pin:", a, b, c, d)
  guess = input ("\nWhat is it? ")
  if guess[0] == pin[0]:
    a = pin[0]
  if guess[1] == pin[1]:
    b = pin[1]
  if guess[2] == pin[2]:
    c = pin[2]
  if guess[3] == pin[3]:
    d = pin[3]
  if a != "_" and b != "_" and c != "_" and d != "_":
    print ("\nYou guessed the pin:", a, b, c, d)
    break
  elif i == 4:
    print ("\nYou ran out of chances! The pin was:", pin)
    

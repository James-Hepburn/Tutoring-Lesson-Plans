import random

number = random.randint (1, 3)

if number == 1:
  letter1 = "C"
  letter2 = "A"
  letter3 = "T"
elif number == 2:
  letter1 = "J"
  letter2 = "O"
  letter3 = "B"
else:
  letter1 = "M"
  letter2 = "O"
  letter3 = "O"

spot1 = spot2 = spot3 = "_"
lives = 3

def print_board (spot1, spot2, spot3, lives):
  print ("\nAmount of lives:", lives, "\n")
  print (spot1, spot2, spot3)

def make_guess (spot1, spot2, spot3, letter1, letter2, letter3, lives):
  guess = input("\nGuess a letter: ")[0].upper()
  if guess != letter1 and guess != letter2 and guess != letter3:
    lives -= 1
  if guess == letter1:
    spot1 = letter1
  if guess == letter2:
    spot2 = letter2
  if guess == letter3:
    spot3 = letter3
  return spot1, spot2, spot3, lives

def play_game (spot1, spot2, spot3, letter1, letter2, letter3, lives):
  if spot1 != "_" and spot2 != "_" and spot3 != "_":
    print ("\nYou won, the word was", letter1, letter2, letter3)
  elif lives == 0:
    print ("\nYou lost, the word was", letter1, letter2, letter3)
  else:
    print_board (spot1, spot2, spot3, lives)
    spot1, spot2, spot3, lives = make_guess (spot1, spot2, spot3, letter1, letter2, letter3, lives)
    play_game (spot1, spot2, spot3, letter1, letter2, letter3, lives)

play_game (spot1, spot2, spot3, letter1, letter2, letter3, lives)
    

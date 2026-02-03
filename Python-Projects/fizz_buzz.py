import time
import os

print ("\nWelcome to the FizzBuzz game! \n")

end = int (input ("What number will you and your opponent end at? "))

current_number = 0
player_one = 0
player_two = 0

while True:
  time.sleep (3)
  os.system ('clear')
  print ("\nCurrent total =", current_number)
  add = int (input ("\nPlayer one, would you like to add 1, 2 or 4? "))
  if add != 1 and add != 2 and add != 4:
    print ("\nYou cheated.\nGame over.")
    break
  else:
    current_number += add
    print ("\nNew total =", current_number)
    if current_number % 3 == 0 and current_number % 5 == 0:
      print ("\nBecause the new total is a multiple of 3 and 5, player one gains 15 points!")
      player_one += 15
    elif current_number % 3 == 0:
      print ("\nBecause the new total is a multiple of 3, player one gains 3 points!")
      player_one += 3
    elif current_number % 5 == 0:
      print ("\nBecause the new total is a multiple of 5, player one gains 5 points!")
      player_one += 5

  if current_number >= end:
    difference = abs (end - current_number)
    print ("\nGame complete!\nBecause you went", difference, "points over, player one losses", different, "points!")
    break

  time.sleep (3)
  os.system ('clear')
  print ("\nCurrent total =", current_number)
  add = int (input ("\nPlayer two, would you like to add 1, 2 or 4? "))
  if add != 1 and add != 2 and add != 4:
    print ("\nYou cheated.\nGame over.")
    break
  else:
    current_number += add
    print ("\nNew total =", current_number)
    if current_number % 3 == 0 and current_number % 5 == 0:
      print ("\nBecause the new total is a multiple of 3 and 5, player two gains 15 points!")
      player_two += 15
    elif current_number % 3 == 0:
      print ("\nBecause the new total is a multiple of 3, player two gains 3 points!")
      player_two += 3
    elif current_number % 5 == 0:
      print ("\nBecause the new total is a multiple of 5, player two gains 5 points!")
      player_two += 5

  if current_number >= end:
    difference = abs (end - current_number)
    print ("\nGame complete!\nBecause you went", difference, "points over, player two losses", difference, "points!")
    time.sleep (2)
    break

time.sleep (3)
os.system ('clear')

print ("\nGame over!\n")
print ("Player one score =", player_one)
print ("Player two score =", player_two)

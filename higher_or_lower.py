import random

computer = random.randint (1, 10)
low = 1
high = 10
lives = 3

print ("\nThe computer's random number is in between", low, "and", high)
print ("You have", lives, "chances left")

guess = int (input ("\nWhat is your guess? "))

if guess == computer:
  print ("\nYou got it!")
else:
  if guess > computer:
    print ("\nSorry, the number is lower.")
    high = guess - 1
  elif guess < computer:
    print ("\nSorry, the number is higher.")
    low = guess + 1
  lives -= 1

  print ("\nThe computer's random number is in between", low, "and", high)
  print ("You have", lives, "chances left")
  
  guess = int (input ("\nWhat is your guess? "))
  
  if guess == computer:
    print ("\nYou got it!")
  else:
    if guess > computer:
      print ("\nSorry, the number is lower.")
      high = guess - 1
    elif guess < computer:
      print ("\nSorry, the number is higher.")
      low = guess + 1
    lives -= 1
  
    print ("\nThe computer's random number is in between", low, "and", high)
    print ("You have", lives, "chances left")
    
    guess = int (input ("\nWhat is your guess? "))
    
    if guess == computer:
      print ("\nYou got it!")
    else:
      if guess > computer:
        print ("\nSorry, the number is lower.")
        high = guess - 1
      elif guess < computer:
        print ("\nSorry, the number is higher.")
        low = guess + 1
      lives -= 1

if lives == 0:
  print ("\nThe answer was", computer)
  

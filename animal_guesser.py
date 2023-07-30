import random

def get_animal ():
  animal = random.randint (1, 3)
  if animal == 1:
    return "cow"
  elif animal == 2:
    return "rhino"
  else:
    return "jellyfish"

def cow (hint):
  if hint == 1:
    return "This animal has 4 parts to its stomach"
  else:
    return "This animal has 32 teeth"

def rhino (hint):
  if hint == 1:
    return "There are 5 species of this animal: white, black, greater one-horned, javan and sumatran"
  else:
    return "This animal can weight the same or more than a car"

def jellyfish (hint):
  if hint == 1:
    return "This animal has no brain or hearts"
  else:
    return "This animal is made up of 95% water"

animal = get_animal ()

if animal == "cow":
  hint1 = cow (1)
  hint2 = cow (2)
elif animal == "rhino":
  hint1 = rhino (1)
  hint2 = rhino (2)
else:
  hint1 = jellyfish (1)
  hint2 = jellyfish (2)

print ("Guess the animal!")

print ("\nHint # 1:", hint1)
guess = input ("\nYour guess: ").lower ()

if guess == animal:
  print ("\nCorrect!")
else:
  print ("\nWrong!")

  print ("\nHint # 2:", hint2)
  guess = input ("\nYour guess: ").lower ()
  
  if guess == animal:
    print ("\nCorrect!")
  else:
    print ("\nWrong!")
    print ("\nThe answer was", animal)

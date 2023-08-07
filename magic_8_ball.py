import random

def get_response ():
  random_number = random.randint (0, 2)
  if random_number == 0:
      return "Yes, definitely."
  elif random_number == 1:
      return "Ask again later."
  elif random_number == 2:
      return "My sources say no."

def run_program ():
  question = input ("\nWhat question would you like to ask? ")
  answer = get_answer ()
  
  print ("The magic 8 ball says ... '", answer, "'")
  
  again = input ("\nWould you like to ask another question? (y or n) ")
  
  if again == "y":
    run_program ()
  else:
    print ("\nGoodbye.")

run_program ()

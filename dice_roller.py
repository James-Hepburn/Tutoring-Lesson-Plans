import random

def one ():
  print ("---------")
  print ("|       |")
  print ("|   *   |")
  print ("|       |")
  print ("---------")

def two ():
  print ("---------")
  print ("| *     |")
  print ("|       |")
  print ("|     * |")
  print ("---------")

def three ():
  print ("---------")
  print ("| *     |")
  print ("|   *   |")
  print ("|     * |")
  print ("---------")

def four ():
  print ("---------")
  print ("| *   * |")
  print ("|       |")
  print ("| *   * |")
  print ("---------")

def five ():
  print ("---------")
  print ("| *   * |")
  print ("|   *   |")
  print ("| *   * |")
  print ("---------")

def six ():
  print ("---------")
  print ("| *   * |")
  print ("| *   * |")
  print ("| *   * |")
  print ("---------")

input ("Press enter to roll the dice: ")
print ()

dice = random.randint (1, 6)

if dice == 1:
  one ()
elif dice == 2:
  two ()
elif dice == 3:
  three ()
elif dice == 4:
  four ()
elif dice == 5:
  five ()
else:
  six ()

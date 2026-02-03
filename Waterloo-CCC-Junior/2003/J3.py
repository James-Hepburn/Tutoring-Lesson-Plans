location = 1

while True:
  move = int (input())
  if move == 0:
    print ("You Quit!")
    break
  location += move
  if location == 9:
    location = 34
  elif location == 40:
    location = 64
  elif location == 67:
    location = 86
  elif location == 54:
    location = 19
  elif location == 90:
    location = 48
  elif location == 99:
    location = 77
  elif location > 100:
    location -= move
  print ("You are now on square", location)
  if location == 100:
    print ("You Win!")
    break
  

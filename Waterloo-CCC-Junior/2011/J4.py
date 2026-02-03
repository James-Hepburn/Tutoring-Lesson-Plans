def boring_left_right (amount, dir):
  global coor, path
  res = True
  for i in range (amount):
    coor[0] += dir
    if coor in path:
      res = False
    path.append (coor[:])
  return res

def boring_down_up (amount, dir):
  global coor, path
  res = True
  for i in range (amount):
    coor[1] += dir
    if coor in path:
      res = False
    path.append (coor[:])
  return res

path = [
  [-1, -5], [-1, -6], [-1, -7],
  [0, -1], [0, -2], [0, -3], [0, -7],
  [1,-3], [1, -7],
  [2, -3], [2, -7],
  [3, -3], [3, -4], [3, -5], [3, -7],
  [4, -5], [4, -7],
  [5, -3], [5, -4], [5, -5], [5, -7],
  [6, -3], [6, -7],
  [7, -3], [7, -4], [7, -5], [7, -6], [7, -7]
]
coor = [-1, -5]

while True:
  instruction = input().split()
  if instruction[0] == 'q':
    break
  elif instruction[0] == 'l':
    if boring_left_right (int (instruction[1]), -1) == False:
      print (coor[0], coor[1], "DANGER")
      break
  elif instruction[0] == 'r':
    if boring_left_right (int (instruction[1]), 1) == False:
      print (coor[0], coor[1], "DANGER")
      break
  elif instruction[0] == 'd':
    if boring_down_up (int (instruction[1]), -1) == False:
      print (coor[0], coor[1], "DANGER")
      break
  elif instruction[0] == 'u':
    if boring_down_up (int (instruction[1]), 1) == False:
      print (coor[0], coor[1], "DANGER")
      break  
  print (coor[0], coor[1], "safe")
       

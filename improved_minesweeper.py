import random, time, os

seen_board = [
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
  ['#', '#', '#', '#', '#', '#', '#', '#', '#'],
]

hidden_board = [
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
]

def add_bombs (amount):
  while amount > 0:
    x = random.randint (0, 8)
    y = random.randint (0, 8)
    if hidden_board [x][y] == ' ':
      hidden_board [x][y] = 'x'
      amount -= 1

def add_numbers ():
  for i in range (9):
    for j in range (9):
      if hidden_board [i][j] == ' ':
        count = 0
        if j + 1 < 9 and hidden_board [i][j + 1] == 'x':
          count += 1
        if j - 1 > -1 and hidden_board [i][j - 1] == 'x':
          count += 1
        if i + 1 < 9 and hidden_board [i + 1][j] == 'x':
          count += 1
        if i - 1 > -1 and hidden_board [i - 1][j] == 'x':
          count += 1
        if i + 1 < 9 and j + 1 < 9 and hidden_board [i + 1][j + 1] == 'x':
          count += 1
        if i + 1 < 9 and j - 1 > -1 and hidden_board [i + 1][j - 1] == 'x':
          count += 1
        if i - 1 > -1 and j + 1 < 9 and hidden_board [i - 1][j + 1] == 'x':
          count += 1
        if i - 1 > -1 and j - 1 > -1 and hidden_board [i - 1][j - 1] == 'x':
          count += 1
        if count != 0:
          hidden_board [i][j] = str (count)

def print_board ():
  print ()
  for i in seen_board:
    print (" ".join (i))
  print ()

def sweeping (row, col):
  if not (0 <= row < 9):
    return
  elif not (0 <= col < 9):
    return 
  elif seen_board [row][col] != '#':
    return 
  elif hidden_board [row][col] != ' ':
    return
  seen_board [row][col] = hidden_board [row][col]
  sweeping (row - 1, col)
  sweeping (row + 1, col)
  sweeping (row, col - 1)
  sweeping (row, col + 1)
  sweeping (row - 1, col - 1)
  sweeping (row - 1, col + 1)
  sweeping (row + 1, col - 1)
  sweeping (row + 1, col + 1)

def check_lost ():
  for i in seen_board:
    if i.count ("x") != 0:
      return True
  return False

def check_win ():
  total = 0
  for i in seen_board:
    total += i.count (' ')
  return total == 71

add_bombs (10)
add_numbers ()

while True:
  time.sleep (1)
  os.system ("clear")
  
  print_board ()

  if check_lost ():
    print ("\nYou lost!")
    break
  elif check_win ():
    print ("\nYou won!")
    break

  print ("1. Add or remove flag")
  print ("2. Uncover square")
  move = int (input ("\nMove? "))

  if move == 1:
    row = int (input ("\nRow? "))
    col = int (input ("Column? "))

    if row > 9 or row < 1 or col > 9 or col < 1:
      print ("\nInvalid input.")
    elif seen_board [row - 1][col - 1] == '#':
      seen_board [row - 1][col - 1] = '?'
    elif seen_board [row - 1][col - 1] == '?':
      seen_board [row - 1][col - 1] = '#'
    else:
      print ("\nInvalid square selection.")

  elif move == 2:
    row = int (input ("\nRow? "))
    col = int (input ("Column? "))

    if row > 9 or row < 1 or col > 9 or col < 1:
      print ("\nInvalid input.")
    elif seen_board [row - 1][col - 1] == '#':
      sweeping (row - 1, col - 1)
      seen_board [row - 1][col - 1] = hidden_board [row - 1][col - 1]
    else:
      print ("\nInvalid square selection.")

  else:
    print ("\nInvalid input.")
    

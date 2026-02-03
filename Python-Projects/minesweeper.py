hidden_board = [
  ['1', '1', '1', ' ', ' '],
  ['1', 'X', '2', '1', '1'],
  ['1', '1', '3', 'X', '2'],
  [' ', ' ', '2', 'X', '2'],
  [' ', ' ', '1', '1', '1']
]

visible_board = [
  ['*', '*', '*', '*', '*'],
  ['*', '*', '*', '*', '*'],
  ['*', '*', '*', '*', '*'],
  ['*', '*', '*', '*', '*'],
  ['*', '*', '*', '*', '*']
]

def print_board (board):
  print ("\n---------------------")
  for i in board:
    print ("| " + " | ".join (i) + " |")
    print ("---------------------")
  print ()

def valid_move (board, row, column):
  condition1 = 1 <= row <= 5 and 1 <= column <= 5
  condition2 = board [row - 1][column - 1] == '*'
  return condition1 and condition2

def update_board (hidden, visible, row, column):
  if valid_move (visible, row, column):
    visible [row - 1][column - 1] = hidden [row - 1][column - 1]
  else:
    print ("\nInvalid move.")

def lost_game (board):
  bomb_count = 0
  for i in board:
    bomb_count += i.count ('X')
  return bomb_count > 0

def won_game (board):
  star_count = 0
  for i in board:
    star_count += i.count ('*')
  return star_count == 3

while True:
  print_board (visible_board)

  if lost_game (visible_board):
    print ("You lost!")
    break
  elif won_game (visible_board):
    print ("You won!")
    break

  row = int(input("Which row? "))
  column = int(input("Which column? "))

  update_board (hidden_board, visible_board, row, column)

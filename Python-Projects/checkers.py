board = [
  [' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'],
  ['X', ' ', 'X', ' ', 'X', ' ', 'X', ' '],
  [' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
  ['O', ' ', 'O', ' ', 'O', ' ', 'O', ' '],
  [' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'],
  ['O', ' ', 'O', ' ', 'O', ' ', 'O', ' ']
]

player1 = 'X'
player2 = 'O'
current_player = player1

def print_board (board):
  print ("\n---------------------------------")
  for i in board:
    print ("| " + " | ".join (i) + " |")
    print ("---------------------------------")
  print ()

def valid_input (board, player, from_row, from_col, to_row, to_col):
  condition1 = 1 <= from_row <= 8 and 1 <= from_col <= 8
  condition2 = 1 <= to_row <= 8 and 1 <= to_col <= 8
  condition3 = board [to_row - 1][to_col - 1] == ' '
  condition4 = board [from_row - 1][from_col - 1] == player
  return condition1 and condition2 and condition3 and condition4

def valid_move (from_row, from_col, to_row, to_col):
  condition1 = abs (to_row - from_row) == 1 and abs (to_col - from_col) == 1
  return condition1

def valid_jump (board, player, from_row, from_col, to_row, to_col):
  condition1 = abs (to_row - from_row) == 2 and abs (to_col - from_col) == 2
  condition2 = board [(from_row + to_row) // 2 - 1][(from_col + to_col) // 2 - 1] != ' '
  condition3 = board [(from_row + to_row) // 2 - 1][(from_col + to_col) // 2 - 1] != player
  return condition1 and condition2 and condition3 

def move_piece (board, player, from_row, from_col, to_row, to_col):
  if valid_input (board, player, from_row, from_col, to_row, to_col):
    if valid_move (from_row, from_col, to_row, to_col):
      board [to_row - 1][to_col - 1] = player
      board [from_row - 1][from_col - 1] = ' '
      return
    if valid_jump (board, player, from_row, from_col, to_row, to_col):
      board [to_row - 1][to_col - 1] = player
      board [from_row - 1][from_col - 1] = ' '
      board [(from_row + to_row) // 2 - 1][(from_col + to_col) // 2 - 1] = ' '
      return
  print ("\nInvalid move.")

def check_win (board, player):
  piece_amount = 0
  for i in board:
    piece_amount += i.count (player)
  return piece_amount == 0

while True:
  print_board (board)
  print ("Player " + current_player + "'s turn!\n")

  from_row = int(input("Enter the row of the checker you want to move: "))
  from_col = int(input("Enter the column of the checker you want to move: "))
  to_row = int(input("Enter the row where you want to move: "))
  to_col = int(input("Enter the column where you want to move: "))

  move_piece (board, current_player, from_row, from_col, to_row, to_col)

  current_player = player2 if current_player == player1 else player1

  if check_win (board, current_player):
    print ("\nPlayer " + current_player + " has lost!")
    break
    

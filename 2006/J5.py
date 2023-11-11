def flip_discs (board, r, c, piece, opponent):
  directions = [[0, 1], [0, -1], [1, 0], [1, 1], [1, -1], [-1, 0], [-1, -1], [-1, 1]]
  for i in directions:
    row = r + i[0]
    col = c + i[1]
    discs = []
    while 0 <= row <= 7 and 0 <= col <= 7 and board[row][col] == opponent:
      discs.append ([row, col])
      row += i[0]
      col += i[1]
    if 0 <= row <= 7 and 0 <= col <= 7 and board[row][col] == piece:
      for j in discs:
        board[j[0]][j[1]] = piece

line = input().split()

a = line[0]
n = int(line[1])

if a == 'a':
  board = [
    [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', 'W', 'B', ' ', ' ', ' '],
    [' ', ' ', ' ', 'B', 'W', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']
  ]
elif a == 'b':
  board = [
    ['B', ' ', ' ', ' ', ' ', ' ', ' ', 'W'],
    [' ', 'B', ' ', ' ', ' ', ' ', 'W', ' '],
    [' ', ' ', 'B', ' ', ' ', 'W', ' ', ' '],
    [' ', ' ', ' ', 'B', 'W', ' ', ' ', ' '],
    [' ', ' ', ' ', 'W', 'B', ' ', ' ', ' '],
    [' ', ' ', 'W', ' ', ' ', 'B', ' ', ' '],
    [' ', 'W', ' ', ' ', ' ', ' ', 'B', ' '],
    ['W', ' ', ' ', ' ', ' ', ' ', ' ', 'B']
  ]
else:
  board = [
    [' ', ' ', 'B', 'B', 'W', 'W', ' ', ' '],
    [' ', ' ', 'B', 'B', 'W', 'W', ' ', ' '],
    [' ', ' ', 'B', 'B', 'W', 'W', ' ', ' '],
    [' ', ' ', 'B', 'B', 'W', 'W', ' ', ' '],
    [' ', ' ', 'B', 'B', 'W', 'W', ' ', ' '],
    [' ', ' ', 'B', 'B', 'W', 'W', ' ', ' '],
    [' ', ' ', 'B', 'B', 'W', 'W', ' ', ' '],
    [' ', ' ', 'B', 'B', 'W', 'W', ' ', ' ']
  ]

index = 2
move = 0

for _ in range (n):
  r = int(line[index]) - 1
  c = int(line[index+1]) - 1
  index += 2
  move += 1

  if move % 2 == 0:
    piece = 'W'
    opponent = 'B'
  else:
    piece = 'B'
    opponent = 'W'

  board [r][c] = piece
  flip_discs (board, r, c, piece, opponent)
  
black = 0
white = 0

for i in board:
  black += i.count ('B')
  white += i.count ('W')

print (black, white)
